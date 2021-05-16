import java.sql.*;
import java.io.*;
import jakarta.servlet.*;
import jakarta.servlet.http.*;

public class country extends HttpServlet {
    public void doGet(HttpServletRequest request,HttpServletResponse response) throws ServletException, IOException {
        
        response.setContentType("text");
        PrintWriter pw=response.getWriter();
        Connection con;
        Statement st;
        ResultSet rs;        
        try
        {
            Class.forName("com.mysql.cj.jdbc.Driver");
            try
            {
                con =DriverManager.getConnection("jdbc:mysql://localhost:3306/user","sree","sree");
                
                try
                {
                    String filter = request.getParameter("val");
                    String srch = " SELECT * FROM countries where name regexp '^"+filter+"' order by name asc;"; 
                    st=con.createStatement();
                    rs=st.executeQuery(srch);

                    while(rs.next() && filter.length()!=0 ){
                        pw.println("<option>"+rs.getString(1)+"</option>");
    
                    }
                }
                  catch(SQLException e)
                {
                    pw.println(e);
                }
            }
            catch (SQLException e)
            {
               pw.println(e);
            }     
        }
        catch(ClassNotFoundException e)
        {
            pw.println(e);
        }
        pw.close();
    }

}