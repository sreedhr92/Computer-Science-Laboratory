import React from 'react';
import logo from './lg1.jpg';
const Registration = () => {
    return ( <div>
        <img src={logo} width={100} height={80} alt="Page logo" />
        <font color="32e0c4">
          <h2>International Gaming Conference Registration</h2>
          <hr className="solid" />
        </font>
        <font color="red">
        <div className="tooltip">Register rules
          <span className="tooltiptext">All fields are mandotory</span>
        </div>
        <p style={{color: 'white'}}>Please fill in the details to get registered for the events and workshop of the conferences</p>
        <font color="black">
          <form>
            <label htmlFor="fname">First name:</label>
            <input type="text" id="fname" name="fname" /><br /><br />
            <label htmlFor="lname">Last  name:</label>
            <input type="text" id="lname" name="lname" /><br /><br />
            <input type="radio" id="male" name="gender" defaultValue="male" />
            <label htmlFor="male">Male</label><br />
            <input type="radio" id="female" name="gender" defaultValue="female" />
            <label htmlFor="female">Female</label><br />
            <input type="radio" id="other" name="gender" defaultValue="other" />
            <label htmlFor="other">Other</label><br /><br /><br />
            <input type="checkbox" id="Phone" name="device1" defaultValue="Phone" />
            <label htmlFor="device1"> I have a Phone</label><br />
            <input type="checkbox" id="iPad" name="device2" defaultValue="iPad" />
            <label htmlFor="device2"> I have a iPad</label><br />
            <input type="checkbox" id="PC" name="device3" defaultValue="PC" />
            <label htmlFor="device3"> I have a PC</label><br /><br />
            <label htmlFor="country">Country:</label>
            <select name="country" id="country"> 
              <option value="India">India</option> 
              <option value="Sri Lanka">Sri Lanka</option> 
              <option value="Australia">Australia</option> 
            </select><br /><br /><br />
            <input type="submit" defaultValue="Submit" /> 
            <input type="reset" defaultValue="Reset" /> <br />
            <label htmlFor="fileselect">Upload your bio:</label>
            <input type="file" name="upload" id="fileselect" />
          </form>
          <font color="black">
            <footer>
              <p style={{color: 'gray'}}>Author: Sreedhar V
                <br /> <a href="mailto:sreedhar18161@cse.ssn.edu.in">Mail id</a></p>
              <i>©Gaming techs designs</i><br />
              <a href="index.html" target="_blank" data-toggle="tooltip" title="This directs you to index page"><i className="fas fa-arrow-left" /></a>
            </footer>
          </font></font></font>
    </div> );
}
 
export default Registration;