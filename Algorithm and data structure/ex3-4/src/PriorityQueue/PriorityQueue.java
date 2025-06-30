package PriorityQueue;

import java.util.Comparator;
import java.util.HashSet;
import java.util.NoSuchElementException;
import java.util.ArrayList;

// PriorityQueue class implementing a min-heap using an ArrayList and a HashSet for fast lookups
public class PriorityQueue<E> implements AbstractQueue<E> {
    private final Comparator<E> comparator; // Comparator to determine the priority
    private final ArrayList<E> heap; // List representing the heap structure
    private final HashSet<E> set; // Set for quick containment checks

    // Constructs a new PriorityQueue with the given comparator
    public PriorityQueue(Comparator<E> comparator) {
        this.comparator = comparator;
        this.heap = new ArrayList<>();
        this.set = new HashSet<>();
    }

    // Returns the index of the left child of the element at index i
    private int getLeftChild(int index) {
        return 2 * index;
    }

    // Returns the index of the right child of the element at index i
    private int getRightChild(int index) {
        return 2 * index + 1;
    }

    // Returns the index of the parent of the element at index i
    private int getParent(int index) {
        return index / 2;
    }

    // Maintains the heap property by moving the element at index i up the heap
    private void heapifyUp(int index) {
        while (index > 0) {
            int parentIndex = getParent(index);
            if (comparator.compare(heap.get(index), heap.get(parentIndex)) < 0) {
                swap(index, parentIndex);
                index = parentIndex;
            } else {
                break; // Stop if heap property is satisfied
            }
        }
    }

    // Maintains the heap property by moving the element at index i down the heap
    private void heapifyDown(int index) {
        int smallest = index;
        int leftChild = getLeftChild(index);
        int rightChild = getRightChild(index);

        // Check if leftChild exists and if it's less than the current node
        if (leftChild < heap.size() && comparator.compare(heap.get(leftChild), heap.get(smallest)) < 0) {
            smallest = leftChild;
        }

        // Check if rightChild exists and if it's less than the current node
        if (rightChild < heap.size() && comparator.compare(heap.get(rightChild), heap.get(smallest)) < 0) {
            smallest = rightChild;
        }

        // If the current node isn't the smallest, swap and repeat
        if (smallest != index) {
            swap(index, smallest);
            heapifyDown(smallest);
        }
    }

    // Swaps two elements in the heap
    private void swap(int i, int j) {
        E temp = heap.get(i);
        heap.set(i, heap.get(j));
        heap.set(j, temp);
    }

    // Checks if the priority queue is empty
    @Override
    public boolean empty() {
        return heap.isEmpty();
    }

    // Adds an element to the priority queue
    @Override
    public boolean push(E element) {
        if (element == null || set.contains(element)) {
            return false;
        }
        heap.add(element);
        set.add(element);
        heapifyUp(heap.size() - 1);
        return true;
    }

    // Checks if the given element is in the priority queue
    @Override
    public boolean contains(E element) {
        return set.contains(element);
    }

    // Gets the element with the highest priority
    @Override
    public E top() {
        if (empty()) {
            throw new NoSuchElementException("The queue is empty");
        }
        return heap.get(0);
    }

    // Removes the element with the highest priority
    @Override
    public void pop() {
        if (empty()) {
            throw new NoSuchElementException("The queue is empty");
        }
        E removed = heap.get(0);
        swap(0, heap.size() - 1);
        heap.remove(heap.size() - 1);
        set.remove(removed);
        heapifyDown(0); // Fixes the whole priority queue
    }

    // Removes a specified element from the queue
    @Override
    public boolean remove(E element) {
        if (!set.contains(element)) {
            return false;
        }
        int index = heap.indexOf(element);
        swap(index, heap.size() - 1);
        heap.remove(heap.size() - 1);
        set.remove(element);
        heapifyDown(index);
        return true;
    }
}
