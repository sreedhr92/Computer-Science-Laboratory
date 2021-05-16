import React from 'react';
import logo from './lg1.jpg';
const Contact = () => {
    return (<div>
        <img src={logo} width={100} height={80} alt="Page logo" />
        <font color="a3d2ca">
          <h2>International Gaming Conference Contacts</h2>
          <hr className="solid" />
        </font>
        <font color="black">
        <p>Thank You for your peaceful participation!<br />If you feel any difficulties or any feedback to about the conference ,You can reach us anytime you need, we will be serving you 24/7</p><p>
        </p><form> 
          <label htmlFor="Description">Feedback Comment:</label> 
          <textarea rows={5} cols={50} name="Description" id="Description" defaultValue={""} /> 
          <input type="submit" defaultValue="Submit" /> 
        </form>
        <footer>
          <font color="black">
            <address>
              Written by Sreedhar.
              <br />
              Visit us at:
              <br />
              gamingtechdesign.com
              <br />
              Box 564, Disneyland
              <br />
              USA
            </address>
            <p style={{color: 'gray'}}>Author: Sreedhar V
              <br /> <a href="mailto:sreedhar18161@cse.ssn.edu.in">Mail id</a></p>
            <i>©Gaming techs designs</i><br />
            <a href="index.html" target="_blank" data-toggle="tooltip" title="This directs you to index page"><i className="fas fa-arrow-left" /></a>
          </font></footer><font color="ffe5b9">
        </font></font>
    </div>  );
}
 
export default Contact;