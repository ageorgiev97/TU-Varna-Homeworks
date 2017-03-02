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

import javafx.fxml.FXML;
import javafx.scene.control.TextField;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.text.Text;
import javafx.stage.Modality;
import javafx.stage.Stage;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;

public class Controller {
    @FXML // изпозвам анотации за да покажа на JavaFX, че свързвам полето от FXML файлът
    private TextField textField1; //декларирам си входното поле

    @FXML private Text actiontarget; // декларирам полето където ще се отпечатва резултата

    @FXML
    protected void doSomething() {
        String input = textField1.getText(); //Присвоявам стойноста на текстовото поле

        String[] strArray = input.split(",");

        ArrayList<Integer> arr=new ArrayList<>();

        for (String s : strArray) {
            arr.add(Integer.parseInt(s));
        }

        Collections.sort(arr);

        if(input.isEmpty()){
            actiontarget.setText("Моля въведете стойност!"); //за празно поле
        }

        actiontarget.setText(arr.toString()); //за празно поле
    }

    @FXML
    private void showAuthor() throws IOException {
        Stage stage;
        Parent root;

        //създавам нов екран за авторът
        stage = new Stage();
        root = FXMLLoader.load(getClass().getResource("fxml/author.fxml")); //сързвам fxml файл
        stage.setScene(new Scene(root,372,130)); // размери на прозореца
        stage.setResizable(false); // забранвам динамичната промяна на размера на прозореца
        stage.setTitle("Автор"); //слагам заглавие на прозореца автор
        stage.initModality(Modality.APPLICATION_MODAL);
        stage.showAndWait();
    }

}
