package Brand;

/*
品牌
 */
public class Brand {
    @Override
    public String toString() {
        return "Brand{" +
                "id=" + id +
                ", brandname='" + brandname + '\'' +
                ", companyname='" + companyname + '\'' +
                ", ordered=" + ordered +
                ", description='" + description + '\'' +
                ", status=" + status +
                '}';
    }

    // id 主键
    private Integer id;
    // 品牌名称
    private String brandname;
    // 企业名称
    private String companyname;
    // 排序字段
    private Integer ordered;
    // 描述信息
    private String description;
    // 状态：0：禁用  1：启用
    private Integer status;

    public Brand() {

    }

    public void setId(Integer id) {
        this.id = id;
    }

    public void setBrandname(String brandname) {
        this.brandname = brandname;
    }

    public void setCompanyname(String companyname) {
        this.companyname = companyname;
    }

    public void setOrdered(Integer ordered) {
        this.ordered = ordered;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public void setStatus(Integer status) {
        this.status = status;
    }

    public Integer getId() {
        return id;
    }

    public String getbrandname() {
        return brandname;
    }

    public String getcompanyname() {
        return companyname;
    }

    public Integer getOrdered(int ordered) {
        return this.ordered;
    }

    public String getDescription() {
        return description;
    }

    public Integer getStatus() {
        return status;
    }

    public Brand(Integer id, String brandname, String companyname, Integer ordered, String description, Integer status) {
        this.id = id;
        this.brandname = brandname;
        this.companyname = companyname;
        this.ordered = ordered;
        this.description = description;
        this.status = status;

    }
}
