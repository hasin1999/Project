package Graph;

import org.junit.runner.JUnitCore;
import org.junit.runner.Result;
import org.junit.runner.notification.Failure;

// Class to run the tests defined in the GraphTest class
public class GraphTestRunner {
    public static void main(String[] args) {
        // Run the GraphTest class
        Result result = JUnitCore.runClasses(GraphTest.class);
        
        // Print any failures
        for (Failure failure : result.getFailures()) {
            System.out.println(failure.toString());
        }
        
        // Print a success message if all tests passed
        System.out.println("\n\n" + result.wasSuccessful() + ": All tests passed successfully");
    }
}
