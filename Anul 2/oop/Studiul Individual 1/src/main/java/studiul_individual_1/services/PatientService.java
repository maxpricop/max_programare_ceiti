package studiul_individual_1.services;

import studiul_individual_1.model.Patient;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class PatientService {
	private final PatientDao dao;
	private final List<Patient> patients = new ArrayList<>();

	public PatientService() {
		try {
			this.dao = new PatientDao();
			patients.addAll(dao.findAll());
		} catch (Exception e) {
			throw new RuntimeException(e);
		}
	}

	public synchronized void sync() throws SQLException {
		patients.clear();
		patients.addAll(dao.findAll());
	}

	public synchronized List<Patient> getAll() {
		return new ArrayList<>(patients);
	}

	public synchronized List<Patient> getByDiagnosis(String diagnosis) {
		Stream<Patient> stream = patients.stream();

		if (diagnosis == null) return stream.filter(p -> p.getDiagnosis() == null).collect(Collectors.toList());
		return stream.filter(p -> diagnosis.equalsIgnoreCase(p.getDiagnosis())).collect(Collectors.toList());
	}

	public synchronized List<Patient> getByPolicyRange(int min, int max) {
		Stream<Patient> stream = patients.stream();

		return stream.filter(p -> p.getPolicyNumber() >= min && p.getPolicyNumber() <= max).collect(Collectors.toList());
	}

	public synchronized Patient getByPolicyNumber(int policy) {
		Stream<Patient> stream = patients.stream();

		return stream.filter(p -> Objects.equals(p.getPolicyNumber(), policy)).findFirst().orElse(null);
	}

	public synchronized long countBySection(String section) {
		Stream<Patient> stream = patients.stream();

		if (section == null) return stream.filter(p -> p.getSection() == null).count();
		return stream.filter(p -> section.equalsIgnoreCase(p.getSection())).count();
	}

	public synchronized List<Patient> getByFirstName(String firstName) {
		Stream<Patient> stream = patients.stream();

		if (firstName == null) return stream.filter(p -> p.getFirstName() == null).collect(Collectors.toList());
		return stream.filter(p -> firstName.equalsIgnoreCase(p.getFirstName())).collect(Collectors.toList());
	}

	public synchronized Patient addPatient(Patient p) throws SQLException {
		String firstName = p.getFirstName();
		if (firstName == null || firstName.isBlank()) throw new IllegalArgumentException("First name is required");

		String lastName = p.getLastName();
		if (lastName == null || lastName.isBlank()) throw new IllegalArgumentException("Last name is required");

		Integer policyNumber = p.getPolicyNumber();
		if (policyNumber == null) throw new IllegalArgumentException("Policy number is required");

		String section = p.getSection();
		if (section == null || section.isBlank()) throw new IllegalArgumentException("Section is required");

		int generatedId = dao.insert(p);
		if (generatedId <= 0) throw new RuntimeException("Failed to insert patient into database");

		p.setId(generatedId);
		patients.add(p);

		return p;
	}

	public synchronized Patient updatePatient(int id, Patient newData) throws SQLException {
		String firstName = newData.getFirstName();
		if (firstName == null || firstName.isBlank()) throw new IllegalArgumentException("First name is required");

		String lastName = newData.getLastName();
		if (lastName == null || lastName.isBlank()) throw new IllegalArgumentException("Last name is required");

		Integer policyNumber = newData.getPolicyNumber();
		if (policyNumber == null) throw new IllegalArgumentException("Policy number is required");

		String section = newData.getSection();
		if (section == null || section.isBlank()) throw new IllegalArgumentException("Section is required");

		int updated = dao.update(id, newData);
		if (updated <= 0) throw new RuntimeException("Failed to update patient in database");

		for (int i = 0; i < patients.size(); i++) {
			Patient p = patients.get(i);

			if (Objects.equals(p.getId(), id)) {
				newData.setId(id);
				patients.set(i, newData);

				return newData;
			}
		}

		newData.setId(id);
		patients.add(newData);

		return newData;
	}

	public synchronized boolean deletePatient(int id) throws SQLException {
		boolean ok = dao.delete(id);

		if (ok) patients.removeIf(p -> Objects.equals(p.getId(), id));
		return ok;
	}
}
