//
//   Project Name:        KratosPfemSolidMechanicsApplication $
//   Created by:          $Author:                  LMonforte $
//   Last modified by:    $Co-Author:                         $
//   Date:                $Date:                    July 2015 $
//   Revision:            $Revision:                      0.0 $
//
//

#if !defined (KRATOS_BORJA_HENCKY_CAM_CLAY_PLASTIC_AXISYM_2D_LAW_H_INCLUDED)
#define       KRATOS_BORJA_HENCKY_CAM_CLAY_PLASTIC_AXISYM_2D_LAW_H_INCLUDED

// System includes

// External includes

// Project includes
#include "custom_constitutive/non_linear_hencky_plastic_axisym_2D_law.hpp"
#include "custom_constitutive/custom_flow_rules/borja_cam_clay_explicit_plastic_flow_rule.hpp"
#include "custom_constitutive/custom_yield_criteria/cam_clay_yield_criterion.hpp"
#include "custom_constitutive/custom_hardening_laws/cam_clay_hardening_law.hpp"


namespace Kratos
{
/**
 * Defines a hyperelastic-plastic isotropic constitutive law J2 in plane strain 2D 
 * With stress split in an isochoric and volumetric parts
 * This material law is defined by the parameters needed by the yield criterion:

 * The functionality is limited to large displacements 
 */



class KRATOS_API(PFEM_SOLID_MECHANICS_APPLICATION) BorjaHenckyCamClayPlasticAxisym2DLaw 
  : public NonLinearHenckyElasticPlasticAxisym2DLaw

{
public:
    /**
     * Type Definitions
     */
    typedef ProcessInfo      ProcessInfoType;
    typedef ConstitutiveLaw         BaseType;
    typedef std::size_t             SizeType;

    typedef FlowRule::Pointer                FlowRulePointer;
    typedef YieldCriterion::Pointer    YieldCriterionPointer;
    typedef HardeningLaw::Pointer        HardeningLawPointer;
    typedef Properties::Pointer            PropertiesPointer;

    /**
     * Counted pointer of HyperElasticPlasticJ2PlaneStrain2DLaw
     */

    KRATOS_CLASS_POINTER_DEFINITION( BorjaHenckyCamClayPlasticAxisym2DLaw );

    /**
     * Life Cycle
     */

    /**
     * Default constructor.
     */
    BorjaHenckyCamClayPlasticAxisym2DLaw();


    BorjaHenckyCamClayPlasticAxisym2DLaw(FlowRulePointer pFlowRule, YieldCriterionPointer pYieldCriterion, HardeningLawPointer pHardeningLaw); 

    /**
     * Copy constructor.
     */
    BorjaHenckyCamClayPlasticAxisym2DLaw (const BorjaHenckyCamClayPlasticAxisym2DLaw& rOther);


    /**
     * Assignment operator.
     */

    //HyperElasticPlasticJ2PlaneStrain2DLaw& operator=(const HyperElasticPlasticJ2PlaneStrain2DLaw& rOther);

    /**
     * Clone function (has to be implemented by any derived class)
     * @return a pointer to a new instance of this constitutive law
     */
    ConstitutiveLaw::Pointer Clone() const override;

    /**
     * Destructor.
     */
    virtual ~BorjaHenckyCamClayPlasticAxisym2DLaw();

    /**
     * Operators
     */

    /**
     * Operations needed by the base class:
     */


    /**
     * This function is designed to be called once to perform all the checks needed
     * on the input provided. Checks can be "expensive" as the function is designed
     * to catch user's errors.
     * @param props
     * @param geom
     * @param CurrentProcessInfo
     * @return
     */
    //int Check(const Properties& rProperties, const GeometryType& rGeometry, const ProcessInfo& rCurrentProcessInfo);

    double& GetValue( const Variable<double>& rThisVariable, double& rValue ) override;

    void SetValue( const Variable<Vector>& rThisVariable, const Vector& rVector, const ProcessInfo& rCurrentProcessInfo) override;


    int Check( const Properties& rMaterialProperties, const GeometryType& rElementGeometry, const ProcessInfo& rCurrentProcessInfo) const override; 
    /**
     * Input and output
     */
    /**
     * Turn back information as a string.
     */
    //String Info() const override;
    /**
     * Print information about this object.
     */
    //void PrintInfo(std::ostream& rOStream) const override;
    /**
     * Print object's data.
     */
    //void PrintData(std::ostream& rOStream) const override;

protected:

    ///@name Protected static Member Variables
    ///@{
    ///@}
    ///@name Protected member Variables
    ///@{
	
    ///@}
    ///@name Protected Operators
    ///@{
    ///@}
    ///@name Protected Operations
    ///@{

    ///@}

private:

    ///@name Static Member Variables
    ///@{


    ///@}
    ///@name Member Variables
    ///@{


    ///@}
    ///@name Private Operators
    ///@{


    ///@}
    ///@name Private Operations
    ///@{


    ///@}
    ///@name Private  Access
    ///@{
    ///@}


    ///@}
    ///@name Serialization
    ///@{
    friend class Serializer;

    void save(Serializer& rSerializer) const override
    {
        KRATOS_SERIALIZE_SAVE_BASE_CLASS( rSerializer, NonLinearHenckyElasticPlasticAxisym2DLaw )
    }

    void load(Serializer& rSerializer) override
    {
        KRATOS_SERIALIZE_LOAD_BASE_CLASS( rSerializer, NonLinearHenckyElasticPlasticAxisym2DLaw )
    }



}; // Class HyperElasticPlasticJ2PlaneStrain2DLaw
}  // namespace Kratos.
#endif // KRATOS_HENCKY_MATSUOKA_PLASTIC_PLANE_STRAIN_2D_LAW_H_INCLUDED defined
