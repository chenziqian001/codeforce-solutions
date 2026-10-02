import android.app.Activity;
import android.content.ContentValues;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ListView;
import java.util.ArrayList;
import java.util.List;

public class ChatActivity extends Activity{
    DBHelper h;
    SQLiteDatabase db;
    ListView lv;
    Button btn;
    EditText et;
    List<String> list;
    ArrayAdapter<String> arr;
    int fId;

    @Override
    protected void onCreate(Bundle b){
        super.onCreate(b);
        setContentView(R.layout.activity_chat);
        h=new DBHelper(this);
        db=h.getWritableDatabase();
        lv=findViewById(R.id.lv);
        btn=findViewById(R.id.btn);
        et=findViewById(R.id.et);
        list=new ArrayList<>();
        arr=new ArrayAdapter<>(this,android.R.layout.simple_list_item_1,list);
        lv.setAdapter(arr);
        
        fId=getIntent().getIntExtra("friend_id",1);
        
        load();
        
        btn.setOnClickListener(v->{
            ContentValues cv=new ContentValues();
            cv.put("friend_id",fId);
            cv.put("content",et.getText().toString());
            cv.put("type",1);
            db.insert("chat",null,cv);
            et.setText("");
            load();
        });
    }

    void load(){
        list.clear();
        String[] args={String.valueOf(fId)};
        Cursor c=db.query("chat",null,"friend_id=?",args,null,null,null);
        while(c.moveToNext()){
            list.add(c.getString(c.getColumnIndexOrThrow("content")));
        }
        c.close();
        arr.notifyDataSetChanged();
    }
}