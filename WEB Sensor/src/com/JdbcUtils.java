package com;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.Properties;

public class JdbcUtils {
	private static Properties dbConfig = new Properties();

	static {
		try {
			dbConfig.load(JdbcUtils.class.getClassLoader().getResourceAsStream("db.properties"));
			Class.forName(dbConfig.getProperty("driver"));
		} catch (Exception e) {
			e.printStackTrace();
		}

	}

	public static Connection getConnection() {
		try {
			return DriverManager.getConnection(dbConfig.getProperty("url"), dbConfig.getProperty("username"),
					dbConfig.getProperty("password"));
		} catch (Exception e) {
		    e.printStackTrace();
		}
		return null;
	}

	public static void release(Connection conn, Statement st, ResultSet rs) {
		if (rs != null) {
			try {
				rs.close();
			} catch (Exception e) {
				e.printStackTrace();
			}
			rs = null;
		}

		if (st != null) {
			try {
				st.close();
			} catch (Exception e) {
				e.printStackTrace();
			}
			st = null;
		}

		if (conn != null) {
			try {
				conn.close();
			} catch (Exception e) {
				e.printStackTrace();
			}
			conn = null;
		}
	}
}
