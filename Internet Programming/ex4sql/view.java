import java.sql.*;
import java.io.*;
import jakarta.servlet.*;
import jakarta.servlet.http.*;

public class view extends HttpServlet {
    public void doGet(HttpServletRequest request,HttpServletResponse response) throws ServletException, IOException {
        
        response.setContentType("text/html");
        PrintWriter pw=response.getWriter();
        Connection con;
        Statement st;
        ResultSet rs;        
        try
        {
            Class.forName("com.mysql.cj.jdbc.Driver");
            try
            {
                con =DriverManager.getConnection("jdbc:mysql://localhost:3306/patient_details","sree","sree");
                
                try
                {
                    String srch = " SELECT * FROM patients;";
                    st=con.createStatement();
                    rs=st.executeQuery(srch);
                    if(rs.next()){
                        pw.println("<html><head><link href=\"table_style.css\" rel=\"stylesheet\" type=\"text/css\"/><head>");
                        pw.println("<br><br><br><br><br><body>");
                        pw.println("<table>");
                        pw.println("<thead>");
                        pw.println("<tr><th>ID</th><th>Name</th><th>Age</th><th>Gender</th><th>Address</th><th>Marital status</th><th>Phone No</th><th>Date of Visit</th></tr>");
                        pw.println("</thead>");
                        pw.println("<tbody>");
                        do{
                            pw.println("<tr><td>"+rs.getString(1)+"</td><td>"+rs.getString(2)+"</td><td>"+rs.getString(3)+"</td><td>"+rs.getString(4)+"</td><td>"+rs.getString(5)+"</td><td>"+rs.getString(6)+"</td><td>"+rs.getString(7)+"</td><td>"+rs.getString(8)+"</td></tr>"); 
                        }while(rs.next());
                        pw.println("</tbody>");
                        pw.println("</table></body></html>");
                    }
                    else
                    {
                        pw.println("<script>");
                        pw.println("alert(\"No data exist \");");
                        pw.println("location='http://localhost:8080/ex4sql/view.html';");
                        pw.println("</script>");
                    }
                }
                  catch(SQLException e)
                {
                    pw.println("<script>");
                    pw.println("alert(\"Retrive the data"+e+" \");");
                    pw.println("location='http://localhost:8080/ex4sql/view.html';");
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