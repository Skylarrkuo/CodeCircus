public class three {
    public static void main(String args[]){
        int i,j,t;
        int a[]=new int[10];
        System.out.println("生成的为:");
        for(i=0;i<10;i++){
            a[i]=(int)(Math.random()*101);
            System.out.printf("%d ",a[i]);
        }
        for(i=0;i<10-1;i++){
            for(j=0;j<10-i-1;j++){
                if(a[j]>a[j+1]){
                    t=a[j+1];
                    a[j+1]=a[j];
                    a[j]=t;
                }
            }
        }
        System.out.println('\n'+"排序后为:");
        for(i=0;i<10;i++){
            System.out.printf("%d ",a[i]);
        }
    }
}