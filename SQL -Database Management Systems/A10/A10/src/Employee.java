/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author sreed
 */
public class Employee extends javax.swing.JFrame {

    /**
     * Creates new form Employee
     */
    public Employee() {
        initComponents();
        this.setSize(971,562);
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        Header = new javax.swing.JLabel();
        Header1 = new javax.swing.JLabel();
        addNewEmployee = new javax.swing.JButton();
        updateEmployee = new javax.swing.JButton();
        searchEmployee = new javax.swing.JButton();
        removeEmployee = new javax.swing.JButton();
        exit = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Employee_Payroll");
        setBackground(new java.awt.Color(255, 255, 255));
        setForeground(java.awt.Color.white);
        setMaximumSize(new java.awt.Dimension(181, 25));
        setMinimumSize(new java.awt.Dimension(181, 25));
        getContentPane().setLayout(null);

        Header.setFont(new java.awt.Font("Arial", 1, 48)); // NOI18N
        Header.setText("Employee Payroll");
        Header.setName(""); // NOI18N
        getContentPane().add(Header);
        Header.setBounds(290, 20, 410, 70);

        Header1.setFont(new java.awt.Font("Arial", 1, 18)); // NOI18N
        Header1.setText("Main Menu");
        getContentPane().add(Header1);
        Header1.setBounds(430, 150, 100, 22);

        addNewEmployee.setBackground(new java.awt.Color(204, 204, 204));
        addNewEmployee.setFont(new java.awt.Font("Arial", 1, 14)); // NOI18N
        addNewEmployee.setText("Add a new employee ");
        addNewEmployee.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                addNewEmployeeActionPerformed(evt);
            }
        });
        getContentPane().add(addNewEmployee);
        addNewEmployee.setBounds(90, 240, 260, 40);

        updateEmployee.setBackground(new java.awt.Color(204, 204, 204));
        updateEmployee.setFont(new java.awt.Font("Arial", 1, 14)); // NOI18N
        updateEmployee.setText("Update an existing employee");
        updateEmployee.setMaximumSize(new java.awt.Dimension(181, 25));
        updateEmployee.setMinimumSize(new java.awt.Dimension(181, 25));
        updateEmployee.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                updateEmployeeActionPerformed(evt);
            }
        });
        getContentPane().add(updateEmployee);
        updateEmployee.setBounds(560, 240, 250, 40);

        searchEmployee.setBackground(new java.awt.Color(204, 204, 204));
        searchEmployee.setFont(new java.awt.Font("Arial", 1, 14)); // NOI18N
        searchEmployee.setText("Search an existing employee");
        searchEmployee.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                searchEmployeeActionPerformed(evt);
            }
        });
        getContentPane().add(searchEmployee);
        searchEmployee.setBounds(90, 330, 260, 40);

        removeEmployee.setBackground(new java.awt.Color(204, 204, 204));
        removeEmployee.setFont(new java.awt.Font("Arial", 1, 14)); // NOI18N
        removeEmployee.setText("Remove an existing employee");
        removeEmployee.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                removeEmployeeActionPerformed(evt);
            }
        });
        getContentPane().add(removeEmployee);
        removeEmployee.setBounds(559, 330, 250, 40);

        exit.setFont(new java.awt.Font("Yu Gothic UI Semibold", 0, 18)); // NOI18N
        exit.setText("Exit");
        exit.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                exitActionPerformed(evt);
            }
        });
        getContentPane().add(exit);
        exit.setBounds(440, 450, 80, 33);

        pack();
        setLocationRelativeTo(null);
    }// </editor-fold>//GEN-END:initComponents

    private void addNewEmployeeActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_addNewEmployeeActionPerformed
        // TODO add your handling code here:
        new addEmployee().setVisible(true);
       // this.dispose();
    }//GEN-LAST:event_addNewEmployeeActionPerformed

    private void updateEmployeeActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_updateEmployeeActionPerformed
        // TODO add your handling code here:
        new updateEmployee().setVisible(true);
      //  this.dispose();
    }//GEN-LAST:event_updateEmployeeActionPerformed

    private void searchEmployeeActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_searchEmployeeActionPerformed
        // TODO add your handling code here:
        new searchEmployee().setVisible(true);
       // this.dispose();
    }//GEN-LAST:event_searchEmployeeActionPerformed

    private void removeEmployeeActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_removeEmployeeActionPerformed
        // TODO add your handling code here:
        new removeEmployee().setVisible(true);
        //this.dispose();
    }//GEN-LAST:event_removeEmployeeActionPerformed

    private void exitActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_exitActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_exitActionPerformed

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
            java.util.logging.Logger.getLogger(Employee.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(Employee.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(Employee.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(Employee.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new Employee().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel Header;
    private javax.swing.JLabel Header1;
    private javax.swing.JButton addNewEmployee;
    private javax.swing.JButton exit;
    private javax.swing.JButton removeEmployee;
    private javax.swing.JButton searchEmployee;
    private javax.swing.JButton updateEmployee;
    // End of variables declaration//GEN-END:variables
}