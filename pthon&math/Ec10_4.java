import java.io.*;
public class Ex10_4 {
    public static void main(String[] args) throws IOException{
        String fileName="D:/myjava/newHello.txt";
        FileReader fr=new FileReader(fileName);
        //获得文件名长度，并按此长度声明一个字符数组
        char[] c=new char[fileName.length()];
        fr.read(c);
        String result=new String(c);
        System.out.println(result);
        fr.close();
    }
}
