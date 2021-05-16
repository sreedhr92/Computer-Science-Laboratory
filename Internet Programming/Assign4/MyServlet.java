import java.io.*;
import jakarta.servlet.*;
import jakarta.servlet.http.*;
public class MyServlet extends HttpServlet {
public void doGet(HttpServletRequest request, HttpServletResponse response)
throws ServletException, IOException {

String EmpId = request.getParameter("EmpId");
String Empname = request.getParameter("Empname");
String desig = request.getParameter("desig");
String dept = request.getParameter("dept");
int BasicSal = Integer.parseInt(request.getParameter("BasicSal"));


String Contact = request.getParameter("Contact");
String Address = request.getParameter("Address");
String birthday = request.getParameter("birthday");
String gender = request.getParameter("gender");
String MStatus = request.getParameter("MStatus");


int Grosspay=BasicSal;

if(desig.equals("CEO"))BasicSal *=4;
else if(desig.equals("HR"))BasicSal *=2.5;
else if(desig.equals("Manager"))BasicSal *=2;
else BasicSal *=1.2;


PrintWriter pw = response.getWriter();

pw.println("<table border =\"1\"width = \"50%\">");
pw.println("<tr><th>ID</th><th>Value</th></tr>");
pw.println("<tr><td>Employee_Id</td><td>"+EmpId+"</td></tr>");
pw.println("<tr><td>Employee_Name</td><td>"+Empname+"</td></tr>");
pw.println("<tr><td>Designation</td><td>"+desig+"</td></tr>");
pw.println("<tr><td>Department</td><td>"+dept+"</td></tr>");
pw.println("<tr><td>Basic_Salary</td><td>"+BasicSal+"</td></tr>");

pw.println("<tr><td>Phone_Number</td><td>"+Contact+"</td></tr>");
pw.println("<tr><td>Address</td><td>"+Address+"</td></tr>");
pw.println("<tr><td>D.O.B</td><td>"+birthday+"</td></tr>");
pw.println("<tr><td>Gender</td><td>"+gender+"</td></tr>");
pw.println("<tr><td>Marital_Status</td><td>"+MStatus+"</td></tr>");

pw.println("<tr><td>Grosspay</td><td>"+Grosspay+"</td></tr>");


pw.println("</table>");
pw.close();
}
}



