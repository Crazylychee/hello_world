package Brand;

import org.junit.Test;
import utils.MyDataSource;

import javax.sql.DataSource;
import java.io.FileInputStream;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.List;
import java.util.Properties;
/**
 * @author yc
 * @date 2023/3/27 13:11
 */

public class BrandTest {
    /**
     * 查询所有
     * 1.SQL:select * from tb_brand
     * 2.参数: 不需要
     * 3.结果:List<brand>
     */
    @Test
    public void testSelectAll()throws Exception{
        //1.获取Connection
        //3.加载配置文件
        Properties prop = new Properties();
        prop.load(new FileInputStream("src/db.properties"));

        //5. 获取数据库连接 Connection
        DataSource dataSource = new MyDataSource();
        Connection conn = dataSource.getConnection();

//        定义SQL
        String sql = "select * from tb_brand;";
        //获取pstmt对象
        PreparedStatement pstmt = conn.prepareStatement(sql);

        //设置参数

        //执行SQL
        ResultSet rs = pstmt.executeQuery();

        //处理结果 List<brand> 封装Brand对象,转载List集合
        Brand brand = null;
        List<Brand> brands = new ArrayList<>();
        while (rs.next()){
            //获取对象
            int id = rs.getInt("id");
            String brandName = rs.getString("brand_name");
            String companyName = rs.getString("company_name");
            int ordered = rs.getInt("ordered");
            String description = rs.getString("description");
            int status = rs.getInt("status");
            //封装Brand对象
            brand = new Brand();
            brand.setId(id);
            brand.setBrandname(brandName);
            brand.setCompanyname(companyName);
            brand.setOrdered(ordered);
            brand.setDescription(description);
            brand.setStatus(status);

            //装载集合
            brands.add(brand);
        }
        System.out.println(brands);
        //释放资源
        rs.close();
        pstmt.close();
        conn.close();

    }

    /**
     * 测试添加
     * @throws Exception
     */
    @Test
    public void testAdd() throws Exception {
        // 接收页面提交的参数
        String brandName = "香飘飘";
        String companyName = "香飘飘";
        int ordered = 1;
        String description = "绕地球一圈";
        int status = 1;
        //1. 获取Connection
        //3. 加载配置文件
        Properties prop = new Properties();
        prop.load(new FileInputStream("src/db.properties"));
        //4. 获取连接池对象
        DataSource dataSource = new MyDataSource();
        //5. 获取数据库连接 Connection
        Connection conn = dataSource.getConnection();
        //2. 定义SQL
        String sql = "insert into tb_brand(brand_name, company_name, ordered, description, status)values(?,?,?,?,?);";
        //3. 获取pstmt对象
//        5.2.4 修改数据
        PreparedStatement pstmt =
                conn.prepareStatement(sql);
        //4. 设置参数
        pstmt.setString(1,brandName);
        pstmt.setString(2,companyName);
        pstmt.setInt(3,ordered);
        pstmt.setString(4,description);
        pstmt.setInt(5,status);
        //5. 执行SQL
        int count = pstmt.executeUpdate();
        // 影响的行数
        //6. 处理结果
        System.out.println(count > 0);
        //7. 释放资源
        pstmt.close();
        conn.close();
    }

    /**
     * 修改
     * 1. SQL：
     update tb_brand
     set brand_name = ?,
     company_name= ?,
     ordered     = ?,
     description = ?,
     status     = ?
     where id = ?
     * 2. 参数：需要，所有数据
     * 3. 结果：boolean
     */
    @Test
    public void testUpdate() throws Exception {
        // 接收页面提交的参数
        String brandName = "香飘飘";
        String companyName = "香飘飘";
        int ordered = 1000;
        String description = "绕地球三圈";
        int status = 1;
        int id = 4;
        //1. 获取Connection
        //3. 加载配置文件
        Properties prop = new Properties();
        prop.load(new FileInputStream("src/db.properties"));
        //4. 获取连接池对象
        DataSource dataSource =new MyDataSource();
        //5. 获取数据库连接 Connection
        Connection conn = dataSource.getConnection();
        //2. 定义SQL
        String sql = " update tb_brand\n" +
                "         set brand_name = ?,\n" +
                "         company_name= ?,\n" +
                "         ordered     = ?,\n" +
                "         description = ?,\n" +
                "         status     = ?\n" +
                "     where id = ?";
        //3. 获取pstmt对象
        PreparedStatement pstmt =
                conn.prepareStatement(sql);
        //4. 设置参数
        pstmt.setString(1,brandName);
        pstmt.setString(2,companyName);
        pstmt.setInt(3,ordered);
//        5.2.5 删除数据
        pstmt.setString(4,description);
        pstmt.setInt(5,status);
        pstmt.setInt(6,id);
        //5. 执行SQL
        int count = pstmt.executeUpdate();
        // 影响的行数
        //6. 处理结果
        System.out.println(count > 0);
        //7. 释放资源
        pstmt.close();
        conn.close();
    }
    /**
     * 测试删除
     * 1. SQL：
     delete from tb_brand where id = ?
     * 2. 参数：需要，id
     * 3. 结果：boolean
     */
    @Test
    public void testDeleteById() throws Exception {
        // 接收页面提交的参数
        int id = 4;
        //1. 获取Connection
        //3. 加载配置文件
        Properties prop = new Properties();
        prop.load(new FileInputStream("src/db.properties"));
        //4. 获取连接池对象
        DataSource dataSource = new MyDataSource();
        //5. 获取数据库连接 Connection
        Connection conn = dataSource.getConnection();
        //2. 定义SQL
        String sql = " delete from tb_brand where id = ? ";
        //3. 获取pstmt对象
        PreparedStatement pstmt =
                conn.prepareStatement(sql);
        //4. 设置参数
        pstmt.setInt(1, id);
        //5. 执行SQL
        int count = pstmt.executeUpdate(); // 影响的行数
        //6. 处理结果
        System.out.println(count > 0);
        //7. 释放资源
        pstmt.close();
        conn.close();
    }
}

