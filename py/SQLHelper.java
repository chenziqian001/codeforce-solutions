import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

public class DBHelper extends SQLiteOpenHelper{
    public DBHelper(Context ctx){
        super(ctx,"Msg.db",null,1);
    }

    @Override
    public void onCreate(SQLiteDatabase db){
        db.execSQL("CREATE TABLE friend(id INTEGER PRIMARY KEY AUTOINCREMENT,name TEXT,face INTEGER)");
        db.execSQL("CREATE TABLE chat(id INTEGER PRIMARY KEY AUTOINCREMENT,friend_id INTEGER,content TEXT,type INTEGER)");
    }

    @Override
    public void onUpgrade(SQLiteDatabase db,int o,int n){}
}