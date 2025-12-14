pulic class example{
    pulic static void main(String [] args){
        myth a=new myth("linera"500);
        myth b=new myth("linerb",900);
        thread a=new
    }
}
public class exmple2{
    pulic static void main(String[] args){
        myth m1=new myth2("xca",1000);
        myth m2=new myth2("xcb",700);

        thread a=new thread(m1);
        thread b=new thread(m2);
        a.strat();
        b.strat();

    }


}

class myth extende thread{
    String naame;
    int time;
    myth(String name,int time){
        this.name =name;
        this time=time;
    }

    public void run(){
        for(int i=1;i<5;i++){
            System.out.println(name+i);
        }
    }
    public void strat(){

    }
}