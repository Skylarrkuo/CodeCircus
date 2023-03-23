public class PC {
    CPU c;
    HardDisk HD;
    void setCPU(int c) {
        CPU.speed = c;
    }
    void setHardDisk(int h) {
        HardDisk.amount = h;
    }
    void show() {
        System.out.println("CPU的速度:"+CPU.speed);
        System.out.println("硬盘的容量为:"+HardDisk.amount);
    }
}
