import java.sql.*;
import java.io.*;
import jakarta.servlet.*;
import jakarta.servlet.http.*;

public class add extends HttpServlet {
    public void doGet(HttpServletRequest request,HttpServletResponse response) throws ServletException, IOException {
        
        response.setContentType("text/html");
        PrintWriter pw=response.getWriter();
        Connection con;
        PreparedStatement ps;       
        try
        {
            Class.forName("com.mysql.cj.jdbc.Driver");
            try
            {
                con =DriverManager.getConnection("jdbc:mysql://localhost:3306/patient_details","sree","sree");
                
                try
                {
                    String insert = "INSERT INTO patients(name,age,id,gender,address,mstat,phone_no,date_of_visit) VALUES(?,?,?,?,?,?,?,?)";
                    ps=con.prepareStatement(insert);
                    ps.setString(1,request.getParameter("name"));
                    ps.setInt(2,Integer.parseInt(request.getParameter("age")));
                    ps.setInt(3,Integer.parseInt(request.getParameter("id")));
                    ps.setString(4,request.getParameter("gender"));
                    ps.setString(5,request.getParameter("address"));
                    ps.setString(6,request.getParameter("mstat"));
                    ps.setString(7,request.getParameter("num"));
                    ps.setDate(8, java.sql.Date.valueOf(request.getParameter("date")));
                    ps.execute();
                    pw.println("<script>");
                    pw.println("alert(\"Inserted Successfully \");");
                    pw.println("location='http://localhost:8080/ex4sql/homepage.html';");
                    pw.println("</script>");
                }
                catch(SQLException e)
                {
                    pw.println("<script>");
                    pw.println("alert(\"Could not Insert data"+e+" \");");
                    pw.println("location='http://localhost:8080/ex4sql/add_user.html';");
                    pw.println("</script>");
                }
            }
            catch (SQLException e)
            {
                pw.println("<script>");
                pw.println("alert(\"Failed to establish connection.Try again Later. Error Code :1 \");");
                pw.println("location='http://localhost:8080/ex4sql/index.html';");
                pw.println("</script>");
            }     
        }
        catch(ClassNotFoundException e)
        {
            pw.println("<script>");
            pw.println("alert(\"Driver class not found.Error Code :0 \");");
            pw.println("location='http://localhost:8080/ex4sql/index.html';");
            pw.println("</script>");
        }
        pw.close();
    }

}