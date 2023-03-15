public class two {
    public static void main(String args[]) {
        int i,j,sum=0;
        for(i=1;i<=200;i++){
            for(j=2;j<=i;j++){
                if(i%j==0){
                    break;
                }
            }
            if(i==j){
                sum=sum+i;
            }
        }
        System.out.println("Sum="+sum);
    }
}

