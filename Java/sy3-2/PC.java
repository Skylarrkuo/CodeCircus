public class PC {
    CPU cpu;
    HardDisk HD;
    void setCPU(CPU c) {
        cpu = c;
    }
    void setHardDisk(HardDisk h) {
        HD = h;
    }
    void show() {
        System.out.println("CPU的速度:"+cpu.getSpeed());
        System.out.println("硬盘的容量为:"+HD.getAmount());
    }
}
