import java.sql.*;

import java.io.*;
import jakarta.servlet.*;
import jakarta.servlet.http.*;

public class Home extends HttpServlet {
    public void doGet(HttpServletRequest request,HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html");
        PrintWriter pw=response.getWriter();
        int flag=0;
        JDBC_CON db=new JDBC_CON();
        db.establish();
        flag=db.valid();
        if(flag==2)
        {
            pw.println("<script>");
            pw.println("alert(\"Failed to establish connection.Try again Later. Error Code :1 \");");
            pw.println("location='http://localhost:8080/ex5sql/index.html';");
            pw.println("</script>");
        }
        else if(flag==3)
        {
            pw.println("<script>");
            pw.println("alert(\"Driver class not found! \");");
            pw.println("location='http://localhost:8080/ex5sql/index.html';");
            pw.println("</script>");
        }
        else
        {
            pw.println("<script>");
            pw.println("alert(\"Connection esatablished successfully! \");");
            pw.println("location='http://localhost:8080/ex5sql/index.html';");
            pw.println("</script>");
        }
    }

}

class JDBC_CON{
    Connection con;
    PreparedStatement ps;
    Statement st;
    CallableStatement cs;
    ResultSet rs;
    int flag;
    public void establish(){
        try
        {
            Class.forName("com.mysql.cj.jdbc.Driver");
            try
            {
                flag=1;
                con =DriverManager.getConnection("jdbc:mysql://localhost:3306/user","sree","sree");
            }
            catch (SQLException e)
            {
                flag=2;
            }     
        }
        catch(ClassNotFoundException e)
        {
            flag=3;
        }  
    }
    public int valid(){
        return flag;
    }
}