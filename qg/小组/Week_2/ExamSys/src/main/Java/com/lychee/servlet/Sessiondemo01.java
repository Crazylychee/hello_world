package com.lychee.servlet;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;

/**
 * @author yc
 * @date 2023/4/10 8:47
 */
public class Sessiondemo01 extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
    //解决乱码问题
        req.setCharacterEncoding("UTF-8");
        resp.setCharacterEncoding("UTF-8");
        resp.setContentType("text/html;charset=utf-8");

        HttpSession session = req.getSession();

        session.setAttribute("name","小明");

        String sessionID= session.getId();

        String id = session.getId();
        if (session.isNew()){
            resp.getWriter().write("session创建成功，ID："+sessionID);
        }else{
            resp.getWriter().write("session以及在服务器中存在了，ID："+sessionID);
        }
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        doGet(req, resp);
    }
}
