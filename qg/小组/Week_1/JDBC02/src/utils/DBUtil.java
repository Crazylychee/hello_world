package utils;


import java.sql.*;

/**
 * @author yc
 * @date 2023/3/29 21:18
 */
public class DBUtil {
    /**
     * 工具类中的构造方法都是私有的
     * 因为工具类当中的方法都是静态的，不需要new对象，直接采用类名调用
     */
    private DBUtil(){}

    //静态代码块在类加载时执行，并且只执行一次
    static {
        try {
            Class.forName("com.mysql.jdbc.Driver");
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
    public static Connection getConnection() throws SQLException{

        return DriverManager.getConnection("jdbc:mysql:///db1?useSSL=false&useServerPrepStmts=true","root",
                "123456");
    }

    /**
     * 关闭资源
     * @param conn 连接对象
     * @param ps 数据库操作对象
     * @param rs 结果集
     */
    public static void close(Connection conn, Statement ps, ResultSet rs){
        if (conn!=null){
            try {
                conn.close();
            }catch (SQLException e){
                e.printStackTrace();
            }
        }
        if (ps!=null){
            try {
                ps.close();
            }catch (SQLException e){
                e.printStackTrace();
            }
        }
        if (rs!=null){
            try {
                rs.close();
            }catch (SQLException e){
                e.printStackTrace();
            }
        }
    }
}
