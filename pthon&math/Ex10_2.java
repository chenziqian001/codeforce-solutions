package chap;
import java.io.*;
public class Ex10_4 {

    public static void main(String[] args)throws IOException {
        // TODO 自动生成的方法存根
        String filename="D://newHello.txt";
        FileReader fr=new FileReader(filename);
        char[] c=new char[1024];
        fr.read(c);
        String result=new String(c);
        System.out.println(result);
        fr.close();
    }

}


