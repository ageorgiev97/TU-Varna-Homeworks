/* Self-програма Array Sorter
 * от Александър Росенов Георгиев, СИТ курс: I, група:2, фак. номер:61662147
 * e-mail: aleksandar.r.georgiev@gmail.com
 */

// Програмта е написана на Java и използва JavaFX
// JavaFX e съвременната алтернатива на Swing. Поддържа се на много платформи включително web и mobile
// Добавил съм графична среда с дизайн разработен от мен включително
// Дизайна е реализиран чрез FXML и JFoenix
// Линк към библиотеката JFoenix https://github.com/jfoenixadmin/JFoenix

package ArraySorter;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class Main extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception{
        Parent root = FXMLLoader.load(getClass().getResource("fxml/sample.fxml"));
        primaryStage.setTitle("Array Sorter");
        primaryStage.setScene(new Scene(root, 590, 390));
        primaryStage.setResizable(false); // Премахвам опцията за динамична промяна на размерите на прозореца
        primaryStage.show();
    }


    public static void main(String[] args) {
        launch(args);
    }
}
