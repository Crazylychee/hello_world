package utils;

import com.alibaba.druid.util.JdbcUtils;

import javax.sql.DataSource;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.SQLFeatureNotSupportedException;
import java.util.LinkedList;
import java.util.Properties;
import java.util.logging.Logger;

/**
 * @author yc
 * @date 2023/4/11 13:26
 */
public class MyDataSource implements DataSource {

    private static LinkedList<Connection> pool = new LinkedList<Connection>();

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
            for (int i = 0; i <=5; i++) {
                Connection connection = DriverManager.getConnection(url,user,password);
                MyConnection myConnection = new MyConnection(connection,pool);
                pool.add(connection);
            }
            connection = DriverManager.getConnection(url,user,password);
        } catch (Exception e) {
            e.printStackTrace();
        }

    }

    @Override
    public Connection getConnection() throws SQLException {

        try {
            if(pool!=null&&pool.size()>0){
                Connection connection = pool.removeFirst();
                return connection;
            }
            Thread.sleep(100);
            Connection connection = getConnection();
            return connection;
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        return null;
    }
    public void closeConnection(Connection connection)
    {
        pool.add(connection);
    }
    @Override
    public Connection getConnection(String username, String password) throws SQLException {
        return null;
    }

    @Override
    public <T> T unwrap(Class<T> iface) throws SQLException {
        return null;
    }

    @Override
    public boolean isWrapperFor(Class<?> iface) throws SQLException {
        return false;
    }

    @Override
    public PrintWriter getLogWriter() throws SQLException {
        return null;
    }

    @Override
    public void setLogWriter(PrintWriter out) throws SQLException {

    }

    @Override
    public void setLoginTimeout(int seconds) throws SQLException {

    }

    @Override
    public int getLoginTimeout() throws SQLException {
        return 0;
    }

    @Override
    public Logger getParentLogger() throws SQLFeatureNotSupportedException {
        return null;
    }
}
