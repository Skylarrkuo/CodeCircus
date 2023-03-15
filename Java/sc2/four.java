public class four {
    public static void main(String args[]){
        long sum=0,i;
        for(i=1;i<=10;i++){
            System.out.printf("%d+",(long)((2.0/9.0)*Math.pow(10,i)));
            sum=sum+(long)((2.0/9.0)*Math.pow(10,i));
        }
        System.out.printf("=%d",sum);
    }
}
