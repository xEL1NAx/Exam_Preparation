import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Stream;

public class StudentLoader {
    /*
      Reads a .txt file line by line.
      Each line MUST be in this format:
      NAME;GRADE

      Example:
      Alice;2
      Bob;4
    */
    public List<Student> loadStudents(String path) throws IOException, InvalidStudentFormatException {

        // List to store all students that were successfully parsed
        List<Student> students = new ArrayList<>();

        // Try-with-resources → automatically closes stream
        try (Stream<String> lines = Files.lines(Paths.get(path))) {

            // Process each line using Streams API
            lines.forEach(line -> {
                try {
                    // Parse each line into a student object
                    Student s = parseLine(line);

                    // Add parsed student
                    students.add(s);

                } catch (InvalidStudentFormatException e) {
                    // If a line is wrong, print error but continue loading others
                    System.out.println("Skipping invalid line: " + e.getMessage());
                }
            });

        } catch (IOException e) {
            // If reading fails → rethrow so main() can handle it
            throw e;
        }

        return students;
    }

    // Parses a single line: "Name;Grade"
    private Student parseLine(String line) throws InvalidStudentFormatException {

        // Split the line by ';'
        String[] parts = line.split(";");

        // Check if line has exactly 2 parts
        if (parts.length != 2) {
            throw new InvalidStudentFormatException("Wrong format: " + line);
        }

        String name = parts[0]; // Extract name
        int grade;

        try {
            // Convert grade from String to int
            grade = Integer.parseInt(parts[1]);

        } catch (NumberFormatException e) {
            // If grade is NOT a number → throw custom exception
            throw new InvalidStudentFormatException("Invalid grade in: " + line);
        }

        // Create and return a new Student object
        return new Student(name, grade);
    }
}
