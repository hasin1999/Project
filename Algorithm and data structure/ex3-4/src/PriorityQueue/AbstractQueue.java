package PriorityQueue;

public interface AbstractQueue<E> {
    public boolean empty();        //checks if the queue is empty -- O(1)
    public boolean push(E e);      //adds an element to the queue -- O(logN)
    public boolean contains(E e);  //checks if an element is in the queue -- O(1)
    public E top();                //accesses the element at the top of the queue -- O(1)
    public void pop();             //removes the element at the top of the queue -- O(logN)
    public boolean remove(E e);    //removes an element if present in the queue -- O(logN)
};
