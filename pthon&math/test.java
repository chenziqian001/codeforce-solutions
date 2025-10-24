public interface CanDance {
    void dance();
}

public interface CanPerform {
    void perform();
}

public interface CanSing {
    void sing();
}

public class Star {
    String name;
    int age;
    char sex;

    public Star(String nm, int ag, char ss) {
        name = nm;
        age = ag;
        sex = ss;
    }

    public String toString() {
        return ("name: " + name + "\n" + "age: " + age + "sex: " + sex + "\n");
    }

    void show() {
        System.out.println("I am famous......");
    }
}


public class Singer extends Star implements CanDance, CanPerform {
    String famousSong;

    public Singer(String nm, int ag, char se, String fmssong) {
        super(nm, ag, se);
        famousSong = fmssong;
    }

    public void sing() {
        System.out.println("Singer: Sing a song");
    }

    public void dance() {
        System.out.println("Singer: I CAN dance !");
    }

    public void perform() {
        System.out.println("Singer: I CAN perform");
    }

    public String toString() {
        return (super.toString() + "famous song: " + famousSong);
    }
}

public class MovieStar extends Star implements CanDance, CanPerform, CanSing {
    String famousMovie;

    public MovieStar(String nm, int ag, char se, String fmsmv) {
        super(nm, ag, se);
        famousMovie = fmsmv;
    }

    public void dance() {
        System.out.println("MovieStar: I CAN dance !");
    }

    public void perform() {
        System.out.println("MovieStar: I CAN perform ");
    }

    public void sing() {
        System.out.println("MovieStar: I CAN Sing ");
    }

    public String toString() {
        return (super.toString() + "famous movie: " + famousMovie);
    }
}


class SuperStar {
    public static void main(String[] args) {
        Singer swift = new Singer("Taylor Swift", 25, 'f', "change");
        System.out.println(swift);
        swift.show();
        swift.sing();
        swift.dance();
        swift.perform();

        System.out.println("************************");
        MovieStar chan = new MovieStar("Jackie Chan", 62, 'm', "policeman story");
        System.out.println(chan);
        chan.show();
        chan.perform();
        chan.sing();
        chan.dance();
    }
}