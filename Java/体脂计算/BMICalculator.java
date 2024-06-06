import javax.swing.SwingUtilities;

public class BMICalculator {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                BMIGUI bmiGUI = new BMIGUI();
                bmiGUI.setVisible(true);
            }
        });
    }
}