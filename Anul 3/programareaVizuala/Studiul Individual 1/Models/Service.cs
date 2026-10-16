namespace BarberDesk.Models;

public class Service {
    public string Name { get; set; } = "";
    public int Minutes {
        get; set;
    }

    public decimal Price {
        get; set;
    }

    public override string ToString() {
        return $"{Name} • {Minutes} min • {Price:0.##} MDL";
    }
}
