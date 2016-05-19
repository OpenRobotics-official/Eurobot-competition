<?xml version="1.0"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:template match="/">
    <HTML>
      <BODY>
        <TABLE style="font:8pt Segoe UI" border="1" CELLSPACING="0" CELLPADDING="1" BGCOLOR="#FFFFFF">
          <THEAD style="font:bold; background-color:#C0C0C0">
            <TR valign="top">
              <xsl:for-each select="/GRID/COLUMNS/COLUMN">
                <TD align="left">
                  <xsl:attribute name="width"><xsl:value-of select="@Width"/></xsl:attribute>
                  <xsl:value-of select="@Caption"/>
                </TD>
              </xsl:for-each>
            </TR>
          </THEAD>
          <xsl:for-each select="GRID/ROWS/ROW">
          <TR valign="top">
            <TD align="left">
              <xsl:value-of select="@Address1"/>
              <xsl:if test="@Address1[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Address2"/>
              <xsl:if test="@Address2[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Address3"/>
              <xsl:if test="@Address3[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Address4"/>
              <xsl:if test="@Address4[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Angle_de_diffusion"/>
              <xsl:if test="@Angle_de_diffusion[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Application_BuildNumber"/>
              <xsl:if test="@Application_BuildNumber[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@ApprovedBy"/>
              <xsl:if test="@ApprovedBy[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Author"/>
              <xsl:if test="@Author[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@CheckedBy"/>
              <xsl:if test="@CheckedBy[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Code_IPC"/>
              <xsl:if test="@Code_IPC[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Code_JEDEC"/>
              <xsl:if test="@Code_JEDEC[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Code_JEITA"/>
              <xsl:if test="@Code_JEITA[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Comment"/>
              <xsl:if test="@Comment[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@CompanyName"/>
              <xsl:if test="@CompanyName[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Component_Kind"/>
              <xsl:if test="@Component_Kind[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@ComponentKind"/>
              <xsl:if test="@ComponentKind[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@ComponentLink1Description"/>
              <xsl:if test="@ComponentLink1Description[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@ComponentLink1URL"/>
              <xsl:if test="@ComponentLink1URL[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@ComponentLink2Description"/>
              <xsl:if test="@ComponentLink2Description[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@ComponentLink2URL"/>
              <xsl:if test="@ComponentLink2URL[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Configuration_des_contacts"/>
              <xsl:if test="@Configuration_des_contacts[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Courant"/>
              <xsl:if test="@Courant[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Courant_de_contact_max_"/>
              <xsl:if test="@Courant_de_contact_max_[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@CurrentDate"/>
              <xsl:if test="@CurrentDate[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@CurrentTime"/>
              <xsl:if test="@CurrentTime[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Date"/>
              <xsl:if test="@Date[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Date_de_cr_ation"/>
              <xsl:if test="@Date_de_cr_ation[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Derni_re_r_vision"/>
              <xsl:if test="@Derni_re_r_vision[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Description"/>
              <xsl:if test="@Description[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Designator"/>
              <xsl:if test="@Designator[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Designator_X_Mil_"/>
              <xsl:if test="@Designator_X_Mil_[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Designator_X_mm_"/>
              <xsl:if test="@Designator_X_mm_[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Designator_Y_Mil_"/>
              <xsl:if test="@Designator_Y_Mil_[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Designator_Y_mm_"/>
              <xsl:if test="@Designator_Y_mm_[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@DesignItemId"/>
              <xsl:if test="@DesignItemId[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Document"/>
              <xsl:if test="@Document[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@DocumentFullPathAndName"/>
              <xsl:if test="@DocumentFullPathAndName[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@DocumentName"/>
              <xsl:if test="@DocumentName[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@DocumentNumber"/>
              <xsl:if test="@DocumentNumber[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@DrawnBy"/>
              <xsl:if test="@DrawnBy[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Edition"/>
              <xsl:if test="@Edition[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Engineer"/>
              <xsl:if test="@Engineer[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Fabriquant"/>
              <xsl:if test="@Fabriquant[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Footprint"/>
              <xsl:if test="@Footprint[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Force__fonctionnement"/>
              <xsl:if test="@Force__fonctionnement[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Hauteur"/>
              <xsl:if test="@Hauteur[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Height_Mil_"/>
              <xsl:if test="@Height_Mil_[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Height_mm_"/>
              <xsl:if test="@Height_mm_[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Ibis_Model"/>
              <xsl:if test="@Ibis_Model[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@ImagePath"/>
              <xsl:if test="@ImagePath[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Index"/>
              <xsl:if test="@Index[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@ItemGUID"/>
              <xsl:if test="@ItemGUID[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Library_Name"/>
              <xsl:if test="@Library_Name[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Library_Reference"/>
              <xsl:if test="@Library_Reference[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@LibRef"/>
              <xsl:if test="@LibRef[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Lien_GCC"/>
              <xsl:if test="@Lien_GCC[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@LogicalDesignator"/>
              <xsl:if test="@LogicalDesignator[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Manufacturer"/>
              <xsl:if test="@Manufacturer[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Manufacturer_1"/>
              <xsl:if test="@Manufacturer_1[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Manufacturer_Part_Number"/>
              <xsl:if test="@Manufacturer_Part_Number[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Manufacturer_Part_Number_1"/>
              <xsl:if test="@Manufacturer_Part_Number_1[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Model_Footprint"/>
              <xsl:if test="@Model_Footprint[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Models"/>
              <xsl:if test="@Models[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@ModifiedDate"/>
              <xsl:if test="@ModifiedDate[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@MSL"/>
              <xsl:if test="@MSL[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Organization"/>
              <xsl:if test="@Organization[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@PartType"/>
              <xsl:if test="@PartType[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@PCB3D"/>
              <xsl:if test="@PCB3D[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@PhysicalPath"/>
              <xsl:if test="@PhysicalPath[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Pic_de_longueur_d_onde"/>
              <xsl:if test="@Pic_de_longueur_d_onde[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Pins"/>
              <xsl:if test="@Pins[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Poid"/>
              <xsl:if test="@Poid[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Pricing"/>
              <xsl:if test="@Pricing[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Prix"/>
              <xsl:if test="@Prix[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Project"/>
              <xsl:if test="@Project[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@ProjectName"/>
              <xsl:if test="@ProjectName[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Puissance"/>
              <xsl:if test="@Puissance[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Puissance_lumineuse"/>
              <xsl:if test="@Puissance_lumineuse[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Quantity"/>
              <xsl:if test="@Quantity[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@R_f_rence_fabriquant"/>
              <xsl:if test="@R_f_rence_fabriquant[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Revision"/>
              <xsl:if test="@Revision[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@RevisionGUID"/>
              <xsl:if test="@RevisionGUID[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Rule"/>
              <xsl:if test="@Rule[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Semi_conducteur"/>
              <xsl:if test="@Semi_conducteur[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@SheetNumber"/>
              <xsl:if test="@SheetNumber[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@SheetTotal"/>
              <xsl:if test="@SheetTotal[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Signal_Integrity"/>
              <xsl:if test="@Signal_Integrity[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Simulation"/>
              <xsl:if test="@Simulation[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@SourceLibraryName"/>
              <xsl:if test="@SourceLibraryName[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Sub_Parts"/>
              <xsl:if test="@Sub_Parts[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Supplier_1"/>
              <xsl:if test="@Supplier_1[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Supplier_Currency_1"/>
              <xsl:if test="@Supplier_Currency_1[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Supplier_Order_Qty_1"/>
              <xsl:if test="@Supplier_Order_Qty_1[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Supplier_Part_Number_1"/>
              <xsl:if test="@Supplier_Part_Number_1[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Supplier_Stock_1"/>
              <xsl:if test="@Supplier_Stock_1[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Supplier_Subtotal_1"/>
              <xsl:if test="@Supplier_Subtotal_1[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Supplier_Unit_Price_1"/>
              <xsl:if test="@Supplier_Unit_Price_1[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@SVHC"/>
              <xsl:if test="@SVHC[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Tension"/>
              <xsl:if test="@Tension[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Tension_DC_nominale_du_contact"/>
              <xsl:if test="@Tension_DC_nominale_du_contact[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Terminaisons_commutateur"/>
              <xsl:if test="@Terminaisons_commutateur[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Time"/>
              <xsl:if test="@Time[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Title"/>
              <xsl:if test="@Title[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Tr"/>
              <xsl:if test="@Tr[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Type"/>
              <xsl:if test="@Type[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Type_d_actionnement"/>
              <xsl:if test="@Type_d_actionnement[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@UniqueIdName"/>
              <xsl:if test="@UniqueIdName[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@UniqueIdPath"/>
              <xsl:if test="@UniqueIdPath[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Variant"/>
              <xsl:if test="@Variant[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@VaultGUID"/>
              <xsl:if test="@VaultGUID[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@Vd"/>
              <xsl:if test="@Vd[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@_"/>
              <xsl:if test="@_[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@_ID_"/>
              <xsl:if test="@_ID_[.='']">&#160;</xsl:if>
            </TD>
            <TD align="left">
              <xsl:value-of select="@_PARENTID_"/>
              <xsl:if test="@_PARENTID_[.='']">&#160;</xsl:if>
            </TD>
          </TR>
          </xsl:for-each>
        </TABLE>
      </BODY>
    </HTML>
  </xsl:template>
</xsl:stylesheet>
