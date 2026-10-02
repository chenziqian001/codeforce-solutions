import android.app.Activity;
import android.content.ContentValues;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ListView;
import java.util.ArrayList;
import java.util.List;

public class FriendActivity extends Activity{
    DBHelper h;
    SQLiteDatabase db;
    ListView lv;
    Button btn;
    List<String> list;
    ArrayAdapter<String> arr;

    @Override
    protected void onCreate(Bundle b){
        super.onCreate(b);
        setContentView(R.layout.activity_friend);
        h=new DBHelper(this);
        db=h.getWritableDatabase();
        lv=findViewById(R.id.lv);
        btn=findViewById(R.id.btn);
        list=new ArrayList<>();
        arr=new ArrayAdapter<>(this,android.R.layout.simple_list_item_1,list);
        lv.setAdapter(arr);
        
        load();
        
        btn.setOnClickListener(v->{
            ContentValues cv=new ContentValues();
            cv.put("name","NewFriend");
            cv.put("face",1);
            db.insert("friend",null,cv);
            load();
        });
    }

    void load(){
        list.clear();
        Cursor c=db.query("friend",null,null,null,null,null,null);
        while(c.moveToNext()){
            list.add(c.getString(c.getColumnIndexOrThrow("name")));
        }
        c.close();
        arr.notifyDataSetChanged();
    }
}