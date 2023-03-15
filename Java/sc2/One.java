public class One {
    public static void main(String args[]){
        int Result=0,sum=1;
        for(int i=1;i<=10;i++){
            for(int j=1;j<=i;j++){
                sum=sum*j;
            }
            Result=Result+sum;
            sum=1;
        }
        System.out.println("Result="+Result);
    }
}
