package t10;
//编写一个Java程序，命名为“ReverseStr.java”，实现如下功能：
//控制台输入一个字符串s，请你反转字符串中单词的顺序。
// 单词是由非空格字符组成的字符串。
// 字符串中每个单词间使用一个或多个空格隔开，单词数量不超过10个。
// 返回单词顺序颠倒且单词之间用单个空格连接的结果字符串。
//注意：输入字符串 s中可能会存在前导空格、尾随空格。
// 返回的结果字符串中，单词间应当仅用单个空格分隔，
// 且不包含任何额外的空格。
//例如：
//输入：I am a student
//输出：student a am I
import java.util.Scanner;
public class  ReverseStr {
    public static void main(String[] args) {
        String s;
        String regex = "\s+";
        String[] a;
        Scanner read=new Scanner(System.in);
        s=read.nextLine();
        a=s.split(regex);
        for(int i=a.length-1;i>=0;i--){
            System.out.printf("%s ",a[i]);
        }
    }
}
