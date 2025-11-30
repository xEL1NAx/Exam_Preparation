public class Student {

    // Student name
    private String name;

    // Student grade
    private int grade;

    // Constructor
    public Student(String name, int grade) {
        this.name = name;   // Set name
        this.grade = grade; // Set grade
    }

    // Getter for name
    public String getName() {
        return name;
    }

    // Getter for grade
    public int getGrade() {
        return grade;
    }

    // Nicely formatted output
    @Override
    public String toString() {
        return name + " (Grade: " + grade + ")";
    }
}
