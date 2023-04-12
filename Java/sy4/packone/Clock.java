package packone;
public class Clock {
    public int hour;
    private int minute;
    protected int second;
    public Clock(int i,int j,int k){
        setAll(i,j,k);
    }
    void setAll(int i,int j,int k){
        hour=i;
        minute=j;
        second=k;
    }
    public int getHour(){
        return hour;
    }
    public int getMinute(){
        return minute;
    }
    public int getSecond(){
        return second;
    }
}
