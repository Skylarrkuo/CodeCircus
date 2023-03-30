import java.util.concurrent.ThreadPoolExecutor.DiscardOldestPolicy;

public class Test {
    public static void main(String args[]) {
        CPU cpu = new CPU();
        cpu.speed = 2200;
        HardDisk disk = new HardDisk();
        disk.amount = 200;
        PC pc = new PC();
        pc.setCPU(cpu);
        pc.setHardDisk(disk);
        pc.show();
    }
}
