import javax.swing.*;
import java.awt.*;
import java.util.List;

public class StudentGUI extends JFrame {

    // Text area where all students will be displayed
    private JTextArea areaOutput;

    // Reference to our loader so the GUI can read files again
    private StudentLoader loader;

    // Path to the file we want to load
    private String filePath;

    public StudentGUI(StudentLoader loader, String filePath) {

        this.loader = loader;       // Save loader reference
        this.filePath = filePath;   // Save path reference

        setTitle("Student Grade Analyzer"); // Window title
        setSize(500, 400);                  // Window size
        setLocationRelativeTo(null);        // Center window on screen
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // Close app when clicking X

        // Create a panel for buttons at the top
        JPanel buttonPanel = new JPanel();  
        buttonPanel.setLayout(new FlowLayout()); // Buttons arranged left-to-right

        // Button that reloads students from the file
        JButton btnLoad = new JButton("Load Students");

        // Button that shows the average grade
        JButton btnAverage = new JButton("Show Average");

        // Add buttons to the panel
        buttonPanel.add(btnLoad);
        buttonPanel.add(btnAverage);

        // Create our text area where results appear
        areaOutput = new JTextArea();
        areaOutput.setEditable(false); // User cannot type in it
        areaOutput.setFont(new Font("Monospaced", Font.PLAIN, 14)); // Nice clean font

        // Scroll pane so text can scroll when there are many students
        JScrollPane scrollPane = new JScrollPane(areaOutput);

        // Add the button bar at the top and text area in the center
        add(buttonPanel, BorderLayout.NORTH);
        add(scrollPane, BorderLayout.CENTER);

        // Add action listener to load button
        btnLoad.addActionListener(e -> loadStudents());

        // Add action listener to average button
        btnAverage.addActionListener(e -> showAverage());

        // Make GUI visible
        setVisible(true);
    }

    // Loads the students and prints them
    private void loadStudents() {

        try {
            // Try to read students from file
            List<Student> students = loader.loadStudents(filePath);

            // Clear output area first
            areaOutput.setText("");

            // Header text
            areaOutput.append("---- Loaded Students ----\n");

            // Print each student using streams
            students.stream().forEach(s -> areaOutput.append(s.toString() + "\n"));

        } catch (Exception ex) {
            // Print error message into GUI
            areaOutput.setText("Error loading students:\n" + ex.getMessage());
        }
    }

    // Calculates and shows average grade
    private void showAverage() {

        try {
            // Load students fresh again (we want latest file version)
            List<Student> students = loader.loadStudents(filePath);

            // Use stream to calculate average
            double avg = students.stream()
                    .mapToInt(Student::getGrade)
                    .average()
                    .orElseThrow(() -> new ArithmeticException("No students found"));

            // Replace output with result
            areaOutput.setText("Average grade is: " + avg);

        } catch (Exception ex) {
            // Print error inside text area
            areaOutput.setText("Error calculating average:\n" + ex.getMessage());
        }
    }
}
