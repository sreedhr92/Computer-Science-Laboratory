/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author sreed
 */
import java.sql.*;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;
import javax.swing.table.DefaultTableModel;
public class tableview extends javax.swing.JFrame {

    /**
     * Creates new form tableview
     */
    public tableview()
    {
        initComponents();
        this.setSize(1350,558);
    }
    public tableview(String eid) {       
        tableDetails(eid);
    }
    public void tableDetails(String eid) {
        try{
        Connection con = DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:orcl", "HR", "1234");
        String query = "Select * from Emp_Payroll where eid = '"+eid+"'";
        PreparedStatement ps = con.prepareStatement(query);
        ResultSet rs = ps.executeQuery();
        DefaultTableModel model =(DefaultTableModel)empTable.getModel();
        model.setRowCount(0);
        if(rs.next())
        {
           model.addRow(new Object[]{rs.getString("eid"),rs.getString("ename"),rs.getString("dob"),
                   rs.getString("sex"),rs.getString("designation"),rs.getString("basic"),rs.getString("da"),
           rs.getString("hra"),rs.getString("pf"),rs.getString("mc"),rs.getString("gross"),
           rs.getString("tot_deduc"),rs.getString("net_pay")});
        }
        else{
            JOptionPane.showMessageDialog(this,"No employee found");
        }
      }
        catch(SQLException se)
        {
            Logger.getLogger(addEmployee.class.getName()).log(Level.SEVERE, null, se);
            JOptionPane.showMessageDialog(this, "DataBase error Search failed!");
        }
    }
    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        header = new javax.swing.JLabel();
        jScrollPane1 = new javax.swing.JScrollPane();
        empTable = new javax.swing.JTable();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);
        setTitle("Table view for Search");
        getContentPane().setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        header.setFont(new java.awt.Font("Arial", 1, 40)); // NOI18N
        header.setText("Table view of records");
        getContentPane().add(header, new org.netbeans.lib.awtextra.AbsoluteConstraints(360, 10, -1, -1));

        empTable.setFont(new java.awt.Font("Yu Gothic UI Semibold", 0, 18)); // NOI18N
        empTable.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {

            },
            new String [] {
                "Employee ID", "Employee Name", "Date of Birth", "Sex", "Designation", "Basic Pay", "DA", "HRA", "PF", "MC", "Gross Pay", "Total detuction", "Net Pay"
            }
        ));
        jScrollPane1.setViewportView(empTable);

        getContentPane().add(jScrollPane1, new org.netbeans.lib.awtextra.AbsoluteConstraints(10, 80, 1330, -1));

        pack();
        setLocationRelativeTo(null);
    }// </editor-fold>//GEN-END:initComponents

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(tableview.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(tableview.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(tableview.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(tableview.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new tableview().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JTable empTable;
    private javax.swing.JLabel header;
    private javax.swing.JScrollPane jScrollPane1;
    // End of variables declaration//GEN-END:variables
}
