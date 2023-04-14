package com.lychee.servlet;

import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

/**
 * @author yc
 * @date 2023/4/12 10:55
 */

// 扩展 HttpServlet 类
public class TestServletBase extends HttpServlet {

    private String message;

    @Override
    public void init() throws ServletException
    {
        // 执行必需的初始化
        message = "Hello World";
    }

    @Override
    public void doGet(HttpServletRequest request,
                      HttpServletResponse response)
            throws ServletException, IOException
    {
        // 设置响应内容类型
        response.setContentType("text/html");

        // 实际的逻辑是在这里
        PrintWriter out = response.getWriter();
        out.println(message);
    }

    @Override
    public void destroy()
    {
        // 什么也不做
    }
}
