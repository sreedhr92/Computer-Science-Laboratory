import React from 'react';
import logo from './beast.jpg';
const Workshop = () => {
    return ( <div>
      <img src={logo} width={100} height={80} alt="Page logo" />
        <font color="a3d2ca">
          <h2>International Gaming Conference Workshop</h2>
          <hr className="solid" />
          <h3 style={{color: 'gray',border: "6px solid violet"}}>List of workshops goes live during the conference--</h3>
        </font>
        <article><br />
          <ul>
            <font color={374045}>
              <li>Predator wars</li>
              <font color="d89216">
                <p>A military exercise carried out to test or improve tactical expertise.</p>
                <font color={374045}>
                  <li>Camping Zones</li>
                  <font color="d89216">
                    <p>Camping goes a long way to improving your mood. It's all to do with serotonin, that wonderful chemical our body produces that helps to make us happy.</p>
                    <font color={374045}>
                      <li>Sporty Minds</li>
                      <font color="d89216">
                        <p>A sports video game, also known as a sports game, is a video game genre that simulates the Sports-based fighting games</p>
                      </font></font></font></font></font></font></ul><font color={374045}><font color="d89216"><font color={374045}><font color="d89216"><font color={374045}><font color="d89216">
                      <font color="red">
                        <aside>To apply for the above Workhops ,first register using this link <a target="_blank" href="registration.html">Register</a></aside>
                      </font></font></font></font></font></font></font></article><font color={374045}><font color="d89216"><font color={374045}><font color="d89216"><font color={374045}><font color="d89216"><font color="red">
                      <footer>
                        <p style={{color: 'gray'}}>Author: Sreedhar V
                          <br /> <a href="mailto:sreedhar18161@cse.ssn.edu.in">Mail id</a></p>
                        <i>©Gaming techs designs</i><br />
                        <a href="index.html" target="_blank" data-toggle="tooltip" title="This directs you to index page"><i className="fas fa-arrow-left" /></a>
                      </footer>
                    </font></font></font></font></font></font></font>
    </div> );
}
 
export default Workshop;