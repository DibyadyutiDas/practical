class PriorityThread extends Thread {
    public PriorityThread(String name) {
        super(name);
    }

    public void run() {
        System.out.println(Thread.currentThread().getName() + " is running with priority " + Thread.currentThread().getPriority());
    }
}

public class ThreadPriorities {
    public static void main(String[] args) {
        PriorityThread t1 = new PriorityThread("Thread-1");
        PriorityThread t2 = new PriorityThread("Thread-2");
        PriorityThread t3 = new PriorityThread("Thread-3");

        t1.setPriority(Thread.MIN_PRIORITY);
        t2.setPriority(Thread.NORM_PRIORITY);
        t3.setPriority(Thread.MAX_PRIORITY);

        t1.start();
        t2.start();
        t3.start();
    }
}