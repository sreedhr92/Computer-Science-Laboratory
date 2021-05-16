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
public class removeEmployee extends javax.swing.JFrame {

    /**
     * Creates new form removeEmployee
     */
    public removeEmployee() {
        initComponents();
        this.setSize(799,455);
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
        rem = new javax.swing.JLabel();
        EmpId = new javax.swing.JTextField();
        Remove = new javax.swing.JButton();
        cancel = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);
        getContentPane().setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        header.setFont(new java.awt.Font("Arial", 1, 40)); // NOI18N
        header.setText("Remove an Employee");
        getContentPane().add(header, new org.netbeans.lib.awtextra.AbsoluteConstraints(180, 20, -1, -1));

        rem.setFont(new java.awt.Font("Yu Gothic UI Semibold", 0, 24)); // NOI18N
        rem.setText("Enter the Employee id");
        getContentPane().add(rem, new org.netbeans.lib.awtextra.AbsoluteConstraints(50, 180, -1, -1));
        getContentPane().add(EmpId, new org.netbeans.lib.awtextra.AbsoluteConstraints(370, 180, 330, 30));

        Remove.setFont(new java.awt.Font("Yu Gothic UI Semibold", 1, 18)); // NOI18N
        Remove.setText("Remove");
        Remove.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                RemoveActionPerformed(evt);
            }
        });
        getContentPane().add(Remove, new org.netbeans.lib.awtextra.AbsoluteConstraints(250, 340, 130, 50));

        cancel.setFont(new java.awt.Font("Yu Gothic UI Semibold", 1, 18)); // NOI18N
        cancel.setText("Cancel");
        cancel.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                cancelActionPerformed(evt);
            }
        });
        getContentPane().add(cancel, new org.netbeans.lib.awtextra.AbsoluteConstraints(460, 340, 130, 50));

        pack();
        setLocationRelativeTo(null);
    }// </editor-fold>//GEN-END:initComponents

    private void cancelActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_cancelActionPerformed
        // TODO add your handling code here:
        this.dispose();
    }//GEN-LAST:event_cancelActionPerformed

    private void RemoveActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_RemoveActionPerformed
        // TODO add your handling code here:
        String eid;
        eid = EmpId.getText().trim();
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
                query = "Delete from Emp_Payroll where eid ='"+eid+"'";
                ps = con.prepareStatement(query);
                ps.executeQuery();
                JOptionPane.showMessageDialog(this, "Employee removed successfully!");
                
            }
            else
            {
                JOptionPane.showMessageDialog(this," No Employees found!");
            }
        }
            catch(SQLException se)
            {
                 Logger.getLogger(addEmployee.class.getName()).log(Level.SEVERE, null, se);
                 JOptionPane.showMessageDialog(this, "DataBase error Remove failed!");
            }
    }                                      
    }//GEN-LAST:event_RemoveActionPerformed

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
            java.util.logging.Logger.getLogger(removeEmployee.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(removeEmployee.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(removeEmployee.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(removeEmployee.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new removeEmployee().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JTextField EmpId;
    private javax.swing.JButton Remove;
    private javax.swing.JButton cancel;
    private javax.swing.JLabel header;
    private javax.swing.JLabel rem;
    // End of variables declaration//GEN-END:variables
}
