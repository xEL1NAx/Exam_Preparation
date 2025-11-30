// Custom exception to handle invalid file lines
public class InvalidStudentFormatException extends Exception {

    // Constructor that passes the message to Exception parent class
    public InvalidStudentFormatException(String message) {
        super(message);
    }
}
