import java.awt.*;
import javax.swing.*;
import javax.swing.border.*;
import com.jgoodies.forms.factories.*;
import net.miginfocom.swing.*;
public class demo extends JFrame {
    public demo() {
        initComponents();
    }

    private void initComponents() {
        // JFormDesigner - Component initialization - DO NOT MODIFY  //GEN-BEGIN:initComponents  @formatter:off
        dialogPane = new JPanel();
        contentPanel = new JPanel();
        buttonBar = new JPanel();
        okButton = new JButton();
        comboBox1 = new JComboBox();
        menuBar3 = new JMenuBar();
        menu1 = new JMenu();
        menuItem3 = new JMenuItem();
        menu2 = new JMenu();
        menu3 = new JMenu();
        scrollPane1 = new JScrollPane();
        list1 = new JList();

        //======== this ========
        setTitle("Demo\u6d4b\u8bd5\u7a97\u4f53");
        var contentPane = getContentPane();
        contentPane.setLayout(new BorderLayout());

        //======== dialogPane ========
        {
            dialogPane.setLayout(new BorderLayout());

            //======== contentPanel ========
            {
                contentPanel.setLayout(new MigLayout(
                    "insets dialog,hidemode 3",
                    // columns
                    "[fill]" +
                    "[fill]" +
                    "[fill]" +
                    "[fill]" +
                    "[fill]" +
                    "[fill]" +
                    "[fill]" +
                    "[fill]" +
                    "[fill]" +
                    "[fill]" +
                    "[fill]" +
                    "[fill]" +
                    "[fill]",
                    // rows
                    "[]" +
                    "[]" +
                    "[]" +
                    "[]" +
                    "[]" +
                    "[]" +
                    "[]"));
            }
            dialogPane.add(contentPanel, BorderLayout.LINE_END);

            //======== buttonBar ========
            {
                buttonBar.setBorder(new EtchedBorder());
                buttonBar.setLayout(new MigLayout(
                    "insets dialog,alignx right",
                    // columns
                    "[fill]" +
                    "[fill]" +
                    "[fill]" +
                    "[fill]" +
                    "[fill]" +
                    "[fill]" +
                    "[fill]" +
                    "[fill]" +
                    "[fill]" +
                    "[button,fill]",
                    // rows
                    null));

                //---- okButton ----
                okButton.setText("OK");
                buttonBar.add(okButton, "tag ok,cell 2 0");
                buttonBar.add(comboBox1, "cell 9 0");
            }
            dialogPane.add(buttonBar, BorderLayout.PAGE_END);

            //======== menuBar3 ========
            {

                //======== menu1 ========
                {
                    menu1.setText("\u5f00\u59cb");

                    //---- menuItem3 ----
                    menuItem3.setText("\u65b0\u5efa");
                    menu1.add(menuItem3);
                }
                menuBar3.add(menu1);

                //======== menu2 ========
                {
                    menu2.setText("\u7f16\u8f91");
                }
                menuBar3.add(menu2);

                //======== menu3 ========
                {
                    menu3.setText("\u8fd0\u884c");
                }
                menuBar3.add(menu3);
            }
            dialogPane.add(menuBar3, BorderLayout.PAGE_START);

            //======== scrollPane1 ========
            {
                scrollPane1.setViewportView(list1);
            }
            dialogPane.add(scrollPane1, BorderLayout.CENTER);
        }
        contentPane.add(dialogPane, BorderLayout.CENTER);
        pack();
        setLocationRelativeTo(getOwner());
        // JFormDesigner - End of component initialization  //GEN-END:initComponents  @formatter:on
    }

    // JFormDesigner - Variables declaration - DO NOT MODIFY  //GEN-BEGIN:variables  @formatter:off
    private JPanel dialogPane;
    private JPanel contentPanel;
    private JPanel buttonBar;
    private JButton okButton;
    private JComboBox comboBox1;
    private JMenuBar menuBar3;
    private JMenu menu1;
    private JMenuItem menuItem3;
    private JMenu menu2;
    private JMenu menu3;
    private JScrollPane scrollPane1;
    private JList list1;
    // JFormDesigner - End of variables declaration  //GEN-END:variables  @formatter:on
}
