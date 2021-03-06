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
public class searchEmployee extends javax.swing.JFrame {

    /**
     * Creates new form searchEmployee
     */
    public searchEmployee() {
        initComponents();
        this.setSize(973,738);
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        id = new javax.swing.JLabel();
        empID = new javax.swing.JTextField();
        name = new javax.swing.JLabel();
        empName = new javax.swing.JTextField();
        dob = new javax.swing.JLabel();
        empDob = new javax.swing.JTextField();
        gender = new javax.swing.JLabel();
        design = new javax.swing.JLabel();
        empDesign = new javax.swing.JTextField();
        pay = new javax.swing.JLabel();
        empBasic = new javax.swing.JTextField();
        search = new javax.swing.JButton();
        header = new javax.swing.JLabel();
        instruction = new javax.swing.JLabel();
        getEmp = new javax.swing.JTextField();
        empGender = new javax.swing.JTextField();
        view = new javax.swing.JButton();
        npay = new javax.swing.JLabel();
        netpay = new javax.swing.JTextField();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);
        getContentPane().setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        id.setFont(new java.awt.Font("Yu Gothic UI Semibold", 0, 18)); // NOI18N
        id.setText("Employee ID");
        getContentPane().add(id, new org.netbeans.lib.awtextra.AbsoluteConstraints(50, 200, 160, -1));
        getContentPane().add(empID, new org.netbeans.lib.awtextra.AbsoluteConstraints(250, 200, 320, -1));

        name.setFont(new java.awt.Font("Yu Gothic UI Semibold", 0, 18)); // NOI18N
        name.setText("Employee Name");
        getContentPane().add(name, new org.netbeans.lib.awtextra.AbsoluteConstraints(50, 280, -1, -1));

        empName.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                empNameActionPerformed(evt);
            }
        });
        getContentPane().add(empName, new org.netbeans.lib.awtextra.AbsoluteConstraints(250, 280, 320, -1));

        dob.setFont(new java.awt.Font("Yu Gothic UI Semibold", 0, 18)); // NOI18N
        dob.setText("Data of Birth");
        getContentPane().add(dob, new org.netbeans.lib.awtextra.AbsoluteConstraints(50, 360, -1, -1));
        getContentPane().add(empDob, new org.netbeans.lib.awtextra.AbsoluteConstraints(250, 360, 320, -1));

        gender.setFont(new java.awt.Font("Yu Gothic UI Semibold", 0, 18)); // NOI18N
        gender.setText("Gender");
        getContentPane().add(gender, new org.netbeans.lib.awtextra.AbsoluteConstraints(50, 430, -1, -1));

        design.setFont(new java.awt.Font("Yu Gothic UI Semibold", 0, 18)); // NOI18N
        design.setText("Designation");
        getContentPane().add(design, new org.netbeans.lib.awtextra.AbsoluteConstraints(50, 500, -1, -1));

        empDesign.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                empDesignActionPerformed(evt);
            }
        });
        getContentPane().add(empDesign, new org.netbeans.lib.awtextra.AbsoluteConstraints(250, 500, 320, -1));

        pay.setFont(new java.awt.Font("Yu Gothic UI Semibold", 0, 18)); // NOI18N
        pay.setText("Basic Pay");
        getContentPane().add(pay, new org.netbeans.lib.awtextra.AbsoluteConstraints(50, 570, -1, -1));

        empBasic.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                empBasicActionPerformed(evt);
            }
        });
        getContentPane().add(empBasic, new org.netbeans.lib.awtextra.AbsoluteConstraints(250, 570, 320, -1));

        search.setFont(new java.awt.Font("Yu Gothic UI Semibold", 1, 18)); // NOI18N
        search.setText("Search");
        search.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                searchActionPerformed(evt);
            }
        });
        getContentPane().add(search, new org.netbeans.lib.awtextra.AbsoluteConstraints(560, 150, -1, -1));

        header.setFont(new java.awt.Font("Arial", 1, 40)); // NOI18N
        header.setText("Search an Employee");
        getContentPane().add(header, new org.netbeans.lib.awtextra.AbsoluteConstraints(290, 10, -1, -1));

        instruction.setFont(new java.awt.Font("Arial", 0, 18)); // NOI18N
        instruction.setText("Enter the Employee Id");
        getContentPane().add(instruction, new org.netbeans.lib.awtextra.AbsoluteConstraints(230, 110, -1, -1));
        getContentPane().add(getEmp, new org.netbeans.lib.awtextra.AbsoluteConstraints(470, 110, 250, -1));
        getContentPane().add(empGender, new org.netbeans.lib.awtextra.AbsoluteConstraints(250, 430, 320, -1));

        view.setFont(new java.awt.Font("Yu Gothic UI Semibold", 0, 18)); // NOI18N
        view.setText("Table view");
        view.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                viewActionPerformed(evt);
            }
        });
        getContentPane().add(view, new org.netbeans.lib.awtextra.AbsoluteConstraints(440, 680, -1, -1));

        npay.setFont(new java.awt.Font("Yu Gothic UI Semibold", 0, 18)); // NOI18N
        npay.setText("Net Pay");
        getContentPane().add(npay, new org.netbeans.lib.awtextra.AbsoluteConstraints(50, 630, -1, -1));
        getContentPane().add(netpay, new org.netbeans.lib.awtextra.AbsoluteConstraints(250, 630, 320, -1));

        pack();
        setLocationRelativeTo(null);
    }// </editor-fold>//GEN-END:initComponents

    private void empNameActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_empNameActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_empNameActionPerformed

    private void empDesignActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_empDesignActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_empDesignActionPerformed

    private void empBasicActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_empBasicActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_empBasicActionPerformed

    private void searchActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_searchActionPerformed
        // TODO add your handling code here:
        String eid;
        eid = getEmp.getText().trim();
        if(eid.isEmpty())
        {
            JOptionPane.showMessageDialog(this,"Please enter the value of the employee to search!");
        }
        else{
            try{
            Connection con = DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:orcl", "HR", "1234");
            String query = "Select * from Emp_Payroll where eid = '"+eid+"'";
            PreparedStatement ps = con.prepareStatement(query);
            ResultSet rs = ps.executeQuery();
            if(rs.next())
            {
                JOptionPane.showMessageDialog(this,"Employee found!");
                empID.setText(rs.getString("eid"));
                empName.setText(rs.getString("ename"));
                empGender.setText(rs.getString("sex"));
                empDesign.setText(rs.getString("designation"));
                empDob.setText(rs.getString("dob"));
                empBasic.setText(rs.getString("basic"));
                netpay.setText(rs.getString("net_pay"));
            }
            else
            {
                JOptionPane.showMessageDialog(this," No Employees found!");
            }
        }
            catch(SQLException se)
            {
                 Logger.getLogger(addEmployee.class.getName()).log(Level.SEVERE, null, se);
                 JOptionPane.showMessageDialog(this, "DataBase error Search failed!");
            }
    }//GEN-LAST:event_searchActionPerformed
    }
    private void viewActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_viewActionPerformed
        // TODO add your handling code here:
        String eid;
        eid = getEmp.getText().trim();
        new tableview(eid).setVisible(true);
        this.dispose();
    }//GEN-LAST:event_viewActionPerformed

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
            java.util.logging.Logger.getLogger(searchEmployee.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(searchEmployee.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(searchEmployee.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(searchEmployee.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new searchEmployee().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel design;
    private javax.swing.JLabel dob;
    private javax.swing.JTextField empBasic;
    private javax.swing.JTextField empDesign;
    private javax.swing.JTextField empDob;
    private javax.swing.JTextField empGender;
    private javax.swing.JTextField empID;
    private javax.swing.JTextField empName;
    private javax.swing.JLabel gender;
    private javax.swing.JTextField getEmp;
    private javax.swing.JLabel header;
    private javax.swing.JLabel id;
    private javax.swing.JLabel instruction;
    private javax.swing.JLabel name;
    private javax.swing.JTextField netpay;
    private javax.swing.JLabel npay;
    private javax.swing.JLabel pay;
    private javax.swing.JButton search;
    private javax.swing.JButton view;
    // End of variables declaration//GEN-END:variables
}
