package utils;

import javax.xml.transform.Result;
import java.io.IOException;
import java.sql.*;
import java.util.Properties;

/**
 * @author yc
 * @date 2023/4/11 14:52
 */
public class JdbcUtils {
    private static Properties properties = new Properties();

    private static Connection connection;

    static {
        try {
            properties.load(JdbcUtils.class.getClassLoader().getResourceAsStream("db.properties"));
            String driverClass = properties.getProperty("jdbc.driverClass");
            String url = properties.getProperty("jdbc.url");
            String user = properties.getProperty("jdbc.user");
            String password = properties.getProperty("jdbc.password");
            Class.forName(driverClass);
            connection = DriverManager.getConnection(url, user, password);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static Connection getConnection() {return connection;}

    public static void close(Connection conn, PreparedStatement preparedStatement, ResultSet resultSet) throws SQLException {
        if (resultSet!=null){
            try {
                resultSet.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        if (preparedStatement!=null){
            try {
                preparedStatement.close();

            } catch (SQLException e) {
                e.printStackTrace();
            }
        }

    }

    private static void forName(String driverClass) {
    }

}
