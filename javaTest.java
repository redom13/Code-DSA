public class javaTest{
    public static void main(String[] args) {
       String s="a,b,c,";
       String[] ans=s.split(",", -1);
       for (var tmp:ans){
        if (tmp.length()>0){
            System.out.println(tmp);
        }
       } 
    }
}