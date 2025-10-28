class Slice {
    int pid;
    long start;
    long end;

    Slice(int pid, long start, long end) {
        this.pid = pid;
        this.start = start;
        this.end = end;
    }
}

class Result {
    Slice[] slices;
    long[][] metrics;
    int sliceCount;

    Result(Slice[] slices, long[][] metrics, int sliceCount) {
        this.slices = slices;
        this.metrics = metrics;
        this.sliceCount = sliceCount;
    }
}

public class RoundRobinCpuQueue {
    public static Result roundRobin(long[] arr, long[] burst, long q) {
        int n = arr.length;
        
        
        Process[] processes = new Process[n];
        for (int i = 0; i < n; i++) {
            processes[i] = new Process(i, arr[i], burst[i]);
        }
        
        for (int i = 1; i < n; i++) {
            Process key = processes[i];
            int j = i - 1;
            while (j >= 0 && processes[j].arrivalTime > key.arrivalTime) {
                processes[j + 1] = processes[j];
                j--;
            }
            processes[j + 1] = key;
        }
        
        
        Process[] readyQueue = new Process[n];
        int front = 0, rear = -1, size = 0;
        long maxSlicesLong = 0;
        for (int i = 0; i < n; i++) {
            long parts = (burst[i] + q - 1) / q; 
            maxSlicesLong += parts;
        }
        int maxSlices = (int) Math.min(maxSlicesLong, (long) Integer.MAX_VALUE);
        Slice[] slices = new Slice[maxSlices];
        int sliceCount = 0;
        long[][] metrics = new long[n][3];  // ct , tat , wt
        boolean[] completed = new boolean[n];
        int completedCount = 0;
        int processIndex = 0;
        long currentTime = 0;
        
        while (completedCount < n) {
            // Add new process
            while (processIndex < n && processes[processIndex].arrivalTime <= currentTime) {
                readyQueue[++rear] = processes[processIndex];
                size++;
                processIndex++;
            }
            
            if (size == 0) {
                if (processIndex < n) {
                    currentTime = processes[processIndex].arrivalTime;
                    continue;
                }
            } else {
                Process current = readyQueue[front];
                for(int i = 0; i < size - 1; i++) {
                    readyQueue[i] = readyQueue[i + 1];
                }
                size--;
                rear--;
                long executionTime = Math.min(q, current.remainingTime);
                
                if (sliceCount < slices.length) {
                    slices[sliceCount++] = new Slice(current.pid, currentTime, currentTime + executionTime);
                }
                
                current.remainingTime -= executionTime;
                currentTime += executionTime;
                
                if (current.remainingTime == 0) {
                    
                    completed[current.pid] = true;
                    completedCount++;

                    metrics[current.pid][0] = currentTime;  
                    metrics[current.pid][1] = currentTime - current.arrivalTime;  
                    metrics[current.pid][2] = metrics[current.pid][1] - current.burstTime;  
                } else {
                    
                    readyQueue[++rear] = current;
                    size++;
                }
            }
        }
        
    return new Result(slices, metrics, sliceCount);
    }
    
    private static class Process {
        int pid;
        long arrivalTime;
        long burstTime;
        long remainingTime;
        
        Process(int pid, long arrivalTime, long burstTime) {
            this.pid = pid;
            this.arrivalTime = arrivalTime;
            this.burstTime = burstTime;
            this.remainingTime = burstTime;
        }
    }
    
    public static void main(String[] args) {
        long[] arr = {0, 2, 4};
        long[] burst = {5, 3, 1};
        long q = 2;
        
        Result result = roundRobin(arr, burst, q);

        System.out.println("Execution Slices:");
        for (int i = 0; i < result.sliceCount; i++) {
            Slice slice = result.slices[i];
            System.out.printf("{%d, %d, %d}%n", slice.pid, slice.start, slice.end);
        }

        System.out.println("\nProcess Metrics (CT, TAT, WT):");
        for (int i = 0; i < result.metrics.length; i++) {
            System.out.printf("pid%d: CT=%d, TAT=%d, WT=%d%n",
                i, result.metrics[i][0], result.metrics[i][1], result.metrics[i][2]);
        }
    }
}