// Import List only if needed, but not required in this shortened Main.
// We keep the import for consistency and future expansion.
import java.util.List;

public class Main {

    public static void main(String[] args) {

        // Create a new StudentLoader object.
        // This object can load students from a file and handle exceptions.
        StudentLoader loader = new StudentLoader();

        /*
         Create the GUI window.
         We pass the loader (so GUI can load the file on button click)
         and the filename "students.txt".
        */
        new StudentGUI(loader, "students.txt");

        // Nothing else is needed here — GUI takes over the entire program.
    }
}
