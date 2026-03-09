CREATE TABLE IF NOT EXISTS patients (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    firstName TEXT NOT NULL,
    lastName TEXT NOT NULL,
    patronymic TEXT,
    address TEXT,
    phone TEXT,
    policyNumber INTEGER UNIQUE NOT NULL,
    section TEXT NOT NULL,
    diagnosis TEXT
);