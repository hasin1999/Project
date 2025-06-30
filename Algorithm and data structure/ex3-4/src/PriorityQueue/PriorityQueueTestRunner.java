package PriorityQueue;

import org.junit.runner.JUnitCore;
import org.junit.runner.Result;
import org.junit.runner.notification.Failure;

// Class to run the tests of PriorityQueueTest
public class PriorityQueueTestRunner {
    public static void main(String[] args) {
        // Run the test class PriorityQueueTest
        Result result = JUnitCore.runClasses(PriorityQueueTest.class);
        
        // Print any failures
        for (Failure failure : result.getFailures()) {
            System.out.println(failure.toString());
        }
        
        // Print a success message if all tests passed
        System.out.println("\n\n" + result.wasSuccessful() + ": All tests passed successfully");
    }
}
